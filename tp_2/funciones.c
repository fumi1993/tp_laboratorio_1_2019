#include "headers.h"

int buscarLibre(eEmpleado listaDeEmpleados[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaDeEmpleados[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarListadoEmpleados(eEmpleado listadoDeEmpleados[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeEmpleados[i].estado==OCUPADO)
        {
            mostrarUnEmpleado(listadoDeEmpleados[i]);
        }

    }
}

void cargarListadoEmpleado(eEmpleado listadoDeEmpleado[], int tam)
{

    int indice;

    indice = buscarLibre(listadoDeEmpleado, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        listadoDeEmpleado[indice] = cargarEmpleado();
    }
    else
    {
        printf("\nNo hay espacio disponible ");
    }

}

eEmpleado cargarEmpleado(void)
{
    eEmpleado Empleado;

    printf("Ingrese id: ");
    scanf("%d", &Empleado.id);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", Empleado.nombre);
    printf("Ingrese apellido: ");
    fflush(stdin);
    scanf("%[^\n]", Empleado.apellido);
    printf("ingrese su salario: ");
    scanf("%f", &Empleado.salario);
    printf("En que sector se trabaja?: ");
    scanf("%d", &Empleado.sector);


    Empleado.estado = OCUPADO;

    return Empleado;
}

void mostrarUnEmpleado(eEmpleado Empleado)
{
    printf("%d %25s %25s %4f %d\n",Empleado.id,Empleado.nombre, Empleado.apellido, Empleado.salario, Empleado.sector);
}

int buscarEmpleadoPorId(eEmpleado* listaDeEmpleados, int cant, int id)
{
    int i;
    int retorno = -1;


    if(listaDeEmpleados!=NULL && cant>0)
    {

     for(i=0; i<cant; i++)
    {
        if(listaDeEmpleados[i].id==id && listaDeEmpleados[i].estado==OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    }


    return retorno;
}
int modificarNombre(eEmpleado listaDeEmpleados[], int cant, int id)
{
    int indice;
    char nombre[30];
    int devolucion = -1;
    char respuesta;
    eEmpleado aux;

    indice = buscarEmpleadoPorId(listaDeEmpleados,cant, id);
    if(indice!=-1)
    {
        aux = listaDeEmpleados[indice];
        mostrarUnEmpleado(aux);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este empleado? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeEmpleados[indice] = aux;
            devolucion = 1;
        }
        else
        {
            devolucion = 0;
        }

    }
    return devolucion;
}
int modificarApellido(eEmpleado listaDeEmpleados[], int cant, int id)
{
    int index;
  //  char apellido[30];
    int devolucion = -1;
    char respuesta;
    eEmpleado aux;

    index = buscarEmpleadoPorId(listaDeEmpleados,cant, id);
    if(index!=-1)
    {
        aux = listaDeEmpleados[index];
        mostrarUnEmpleado(aux);
        printf("Ingrese el nuevo apellido: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este empleado? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeEmpleados[index] = aux;
            devolucion = 1;
        }
        else
        {
            devolucion = 0;
        }

    }
    return devolucion;
}
int modificarSalario(eEmpleado listaDeEmpleados[], int cant, int id)
{
    int index;
    float salario;
    int devolucion = -1;
    char respuesta;
    eEmpleado aux;

    index = buscarEmpleadoPorId(listaDeEmpleados,cant, id);
    if(index!=-1)
    {
        aux = listaDeEmpleados[index];
        mostrarUnEmpleado(aux);
        printf("Ingrese el nuevo salario : ");
        fflush(stdin);
        scanf("%2f",&salario);
        printf("Esta seguro que desea modificar este empleado? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeEmpleados[index] = aux;
            devolucion = 1;
        }
        else
        {
            devolucion = 0;
        }

    }
    return devolucion;
}

int modificarSector(eEmpleado listaDeEmpleados[], int cant, int id)
{
    int index;
    int sector;
    int devolucion = -1;
    char respuesta;
    eEmpleado aux;


    index = buscarEmpleadoPorId(listaDeEmpleados,cant, id);
    if(index!=-1)
    {
        aux = listaDeEmpleados[index];
        mostrarUnEmpleado(aux);
        printf("Ingrese el nuevo sector : ");
        fflush(stdin);
        scanf("%d",&sector);
        printf("Esta seguro que desea modificar este empleado? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeEmpleados[index] = aux;
            devolucion = 1;
        }
        else
        {
            devolucion = 0;
        }

    }
    return devolucion;
}



int eliminarEmpleado(eEmpleado listaDeEmpleados[], int tam)
{
    int id;
    int i;
    char respuesta;

    int devolucion = -1;

    mostrarListadoEmpleados(listaDeEmpleados,tam);

    printf("Ingrese el id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(listaDeEmpleados[i].id==id && listaDeEmpleados[i].estado==OCUPADO)
        {
            mostrarUnEmpleado(listaDeEmpleados[i]);
            printf("Esta seguro que desea eliminar este empleado? :");
            respuesta = getche();
            if(respuesta=='s')
            {
                listaDeEmpleados[i].estado = LIBRE;
                devolucion = 1;
            }
            else
            {
                devolucion = 0;
            }
            break;
        }

    }

    return devolucion ;
}

void ordenarEmpleados(eEmpleado listaDeEmpleados[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleados;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listaDeEmpleados[i].apellido,listaDeEmpleados[j].apellido)>0)
            {
                auxEmpleados = listaDeEmpleados[i];
                listaDeEmpleados[i] = listaDeEmpleados[j];
                listaDeEmpleados[j] = auxEmpleados;
            }

            else
            {
                if(strcmp(listaDeEmpleados[i].apellido,listaDeEmpleados[j].apellido)==0)
                {
                    if(listaDeEmpleados[i].sector>listaDeEmpleados[j].sector)
                    {
                        auxEmpleados = listaDeEmpleados[i];
                        listaDeEmpleados[i] = listaDeEmpleados[j];
                        listaDeEmpleados[j] = auxEmpleados;
                    }
                }
            }
        }

    }
}




