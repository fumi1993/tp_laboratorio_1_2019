#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[29];
    char apellido[29];
    float salario;
    int sector;
    int estado;
}eEmpleado;

eEmpleado cargarEmpleado(void);
void mostrarUnEmpleado(eEmpleado);
int buscarLibre(eEmpleado*,int);
void cargarListadoEmpleado(eEmpleado[],int);
void mostrarListadoEmpleados(eEmpleado[],int);
int eliminarEmpleado(eEmpleado[],int);
int buscarEmpleadoPorId(eEmpleado[], int,int);
int modificarNombre(eEmpleado [],int,int );
int modificaApellido(eEmpleado[],int,int );
int modificarSalario(eEmpleado[] ,int,int );
int modificarSector(eEmpleado[] ,int,int );
