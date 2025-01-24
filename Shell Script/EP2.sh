#!/bin/bash
if [ $# -ne 5 ]; then
    echo Falta parâmetros
    exit 1
fi

TEMPO=$1
ARQUIVO=$2
LIM_CPU=$( echo "100-$3" | bc -l )
TOKEN_BOT=$4
ID_BOT=$5
CONT=1
CPU_TOTAL=0
TEMPO_FORA=0
IFS='
'

while [ true ]; do
    DATA=$( date +%d/%m/%Y ) 
    HORA=$( date +%H:%M:%S )
    CPU_OCIOSA=$( top -n 1 | grep Cpu | cut -c150-154 )
    FORA_DO_AR=$( netstat -anp 2>/dev/null | grep 45052 | grep LISTEN | wc -l )
    N_IPS_CONECT=$( netstat -anp 2>/dev/null | grep 45052 | grep ESTABLISHED | wc -l )

    curl -s --data "text==== Nova Verificação do Servidor ===${IFS}Data: ${DATA} ${IFS}Hora: ${HORA}" https://api.telegram.org/bot$TOKEN_BOT/sendMessage?chat_id=$ID_BOT 1>/dev/null
    echo Data: ${DATA} >> ${ARQUIVO}
    echo Hora: ${HORA} >> ${ARQUIVO}
    echo === Nova Verificação do Servidor ===
    echo Data: ${DATA}
    echo Hora: ${HORA}

    if [ ${N_IPS_CONECT} -ne 0 ]; then
        curl -s --data "text=IPs conectados:" https://api.telegram.org/bot$TOKEN_BOT/sendMessage?chat_id=$ID_BOT 1>/dev/null
        echo IPs conectados: >> ${ARQUIVO}
        echo IPs conectados:
        for item in $( netstat -anp 2>/dev/null | grep 45052 | grep ESTABLISHED | cut -c45-53 | uniq ); do
            curl -s --data "text=${item}" https://api.telegram.org/bot$TOKEN_BOT/sendMessage?chat_id=$ID_BOT 1>/dev/null
            echo ${item} >> ${ARQUIVO}
            echo ${item}
        done
    fi

    if [ $( echo "${CPU_OCIOSA}<${LIM_CPU}" | bc -l ) -eq 1 ]; then
        curl -s --data "text=Ociosidade da CPU: ${CPU_OCIOSA}%" https://api.telegram.org/bot$TOKEN_BOT/sendMessage?chat_id=$ID_BOT 1>/dev/null
        echo Ociosidade da CPU: ${CPU_OCIOSA}%
    fi
    echo Ociosidade da CPU: ${CPU_OCIOSA}% >> ${ARQUIVO}

    if [ ${FORA_DO_AR} -eq 0 ]; then
        curl -s --data "text=O servidor está fora do ar" https://api.telegram.org/bot$TOKEN_BOT/sendMessage?chat_id=$ID_BOT 1>/dev/null
        echo O servidor esta fora do ar >> ${ARQUIVO}
        echo O servidor esta fora do ar
        let TEMPO_FORA=${TEMPO_FORA}+${TEMPO}
    fi

    echo ${IFS} >> ${ARQUIVO}
    echo ${IFS}

    #Outras informações para o arquivo
    CPU_TOTAL=$( echo "${CPU_OCIOSA}+${CPU_TOTAL}" | bc -l )
    if [ ${CONT} -eq 100 ]; then
        MEDIA=$( echo "scale=2; ${CPU_TOTAL}/100" | bc -l )
        echo Media das 100 últimas medições de ociosidade de CPU: ${MEDIA}% >> ${ARQUIVO}
        echo Tempo em que o servidor ficou fora do ar nas ultimas 100 medicoes: ${TEMPO_FORA} >> ${ARQUIVO}
        echo ${IFS} >> ${ARQUIVO}
        CPU_TOTAL=0
        TEMPO_FORA=0
        CONT=1
    fi

    let CONT=${CONT}+1
    sleep ${TEMPO}
done

exit 0