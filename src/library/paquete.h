#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
#include <errno.h>
#include<commons/log.h>
#include<commons/string.h>
#include "buffer.h"
#include "conexion.h"

typedef struct {
    uint8_t codigo_operacion;
    t_buffer* buffer;
} t_paquete;

//Crea un paquete a partir de un codigo de operacion y un t_buffer
t_paquete *crear_paquete(u_int8_t operacion, t_buffer *buffer);

//Envia un t_paquete a partir de un socket 
void enviar_paquete(t_paquete *paquete, uint32_t socket);

//Recibe un t_paquete y lo devuelve a partir de un socket
t_paquete *recibir_paquete(uint32_t socket);

//Libera la memoria asociada a un paquete
void destruir_paquete(t_paquete *paquete);

