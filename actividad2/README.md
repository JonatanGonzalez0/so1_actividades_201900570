# GitHub User Greeting Script

Script Bash realizado para consultar la API de GitHub y obtener información sobre un usuario específico. El script imprime un mensaje y guarda este mensaje en un archivo de log. Además, se configura un cron job para ejecutar el script cada 5 minutos.

## Instalación y Configuración
1. **Instala las dependencias**:
    ```bash
    sudo apt-get update
    sudo apt-get install curl jq
    ```

2. **Asegúrate de que `cron` está instalado y corriendo**:
    ```bash
    sudo apt-get install cron
    sudo service cron start
    ```

3. **Crea el script de Bash** y dale permisos de ejecución:
    ```bash
    chmod +x actividad2/github.sh
    ```

4. **Configura el cron job**:
    Abre el archivo crontab para edición:
    ```bash
    crontab -e
    ```
    Agrega la siguiente línea para ejecutar el script cada 5 minutos:
    ```bash
    */5 * * * * actividad2/github.sh
    ```
    **Configuración del cron job**:
    ![Configuración del Cron Job](img/cron%20Job.png)

2. **Verifica el archivo de log**:
    ```bash
    fecha=$(date +%Y-%m-%d)
    log_file="/tmp/$fecha/saludos.log"
    cat $log_file
    ```

    **Log de ejecucion**:
    ![Logs de ejecucion](img/Logs%20tmp.png)
    