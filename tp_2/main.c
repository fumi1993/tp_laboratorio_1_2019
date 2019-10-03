#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define A 1000
//lamento mucho la desprolijidad, no tube mucho tiempo para hacer este tp. si se me permite recuperarlo lo voy a ir modificando.
int main()
{
   eEmpleado listaDeEmpleados[A];
    int i;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeEmpleados[i].estado=LIBRE;
    }



    do
    {
        printf("\n1.Cargar\n2.Modificar\n3.Eliminar\n4.Mostrar\n7.Salir");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoEmpleado(listaDeEmpleados,A);

            break;
       case 2:
           printf("\ningrese que dato modificar ");
           printf("\n1nombre : \n2apellido : \n3salario : \n4sector : \n5volver al menu anterior :");
           switch(opcion)
           {
           case 1:
                modificarNombre(listaDeEmpleados,A,listaDeEmpleados[i].id);
               break;
           case 2:
                modificarApellido(listaDeEmpleados,A,listaDeEmpleados[i].id);
                break;
           case 3:
                modificarSalario(listaDeEmpleados,A,listaDeEmpleados[i].id);
               break;
           case 4:
                modificarSector(listaDeEmpleados,A,listaDeEmpleados[i].id);
               break;
           case 5:
               printf("\nvolviendo al menu anterior ");
               break;
           }


            break;
        case 3:
            eliminarEmpleado(listaDeEmpleados,A);
            break;
        case 4:
            mostrarListadoEmpleados(listaDeEmpleados, A);
            break;

        }
    }
    while(opcion!=7);
    return 0;
}

