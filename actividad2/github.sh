#!/bin/bash

# Leer la variable GITHUB_USER
GITHUB_USER="JonatanGonzalez0"

# Consultar la URL
response=$(curl -s "https://api.github.com/users/$GITHUB_USER")

# Obtener valores de la respuesta JSON
user_id=$(echo $response | jq -r '.id')
created_at=$(echo $response | jq -r '.created_at')

# Imprimir el mensaje
echo "Hola $GITHUB_USER. User ID: $user_id. Cuenta fue creada el: $created_at."

# Crear un log file en /tmp/<fecha>/saludos.log
fecha=$(date +%Y-%m-%d)
log_dir="/tmp/$fecha"
mkdir -p $log_dir
log_file="$log_dir/saludos.log"

# Escribir el mensaje en el log file
echo "Hola $GITHUB_USER. User ID: $user_id. Cuenta fue creada el: $created_at." >> $log_file
