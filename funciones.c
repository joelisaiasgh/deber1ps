#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Definición del array de usuarios
struct Usuario lUsuarios[MAX_USUARIOS];
struct Producto lProductos[MAX_PRODUCTOS];

struct Usuario crear_usuario(struct Usuario admin, char nombre[20], char username[20], char password[10], struct Usuario lista[]) {
    struct Usuario u;
    int opcion2;

    if (admin.tipo == ADMINISTRADOR) {
        strncpy(u.nombre, nombre, sizeof(u.nombre));
        strncpy(u.username, username, sizeof(u.username));
        strncpy(u.password, password, sizeof(u.password));

        printf("Tipo de usuario:\n");
        printf("[1] Administrador\n");
        printf("[2] Bodeguero\n");
        printf("[3] Vendedor\n");
        printf("[4] Default");
        scanf("%i", &opcion2);
        switch (opcion2) {
            case 1:
                u.tipo = ADMINISTRADOR;
                break;

            case 2:
                u.tipo = BODEGUERO;
                break;

            case 3:
                u.tipo = VENDEDOR;
                break;

            case 4:
                printf("Usuario asignado como vendedor\n");
                printf("Si desea cambiar el tipo de usuario, podrá hacerlo desde el menú\n");
                u.tipo = VENDEDOR;
                break;

            default:
                printf("Usuario asignado como vendedor\n");
                printf("Si desea cambiar el tipo de usuario, podrá hacerlo desde el menú\n");
                u.tipo = VENDEDOR;
                break;
        }

        // Guardar el nuevo usuario en la lista
        int existe = 0;
        int contador = 0;

        // Buscar un espacio vacío y verificar si el usuario ya existe
        for (int i = 0; i < 10; i++) {
            if (lista[i].username[0] != '\0') {
                contador++;
            }
            if (strcmp(lista[i].username, u.username) == 0) {
                existe = 1;
                break;
            }
        }

        if (existe == 0 && contador < 10) {
            // El usuario no existe y hay espacio vacío en el arreglo

            // Crear el nuevo usuario
            lista[contador] = u;
            contador++;

            // Guardar la lista de usuarios actualizada en el archivo
            guardar_usuarios(lista, contador);
        } else {
            printf("El usuario ya existe o la lista está llena.\n");
        }
    } else {
        printf("ERROR. Usted no es administrador.\n");
    }
    return u;
}


struct Usuario actualizar_usuario(struct Usuario admin, struct Usuario usuario, struct Usuario lista[]) {
    int opcion;
    char nombre[20];
    char user[10];
    char password[10];
    int opcion2;

    if (admin.tipo == ADMINISTRADOR) {
        printf("Seleccione una categoría:\n");
        printf("[1] Nombre\n");
        printf("[2] Contraseña\n");
        printf("[3] Tipo de usuario\n");
        printf("[4] Cancelar\n");

        scanf("%i", &opcion);

      switch (opcion) {
          case 1:
              printf("Nombre: ");
              scanf("%s", nombre);
            printf("%s %s %s \n\n\n", usuario.nombre, usuario.username, usuario.password);
              strncpy(usuario.nombre, nombre, sizeof(usuario.nombre) - 1);
              usuario.nombre[sizeof(usuario.nombre) - 1] = '\0'; // Añadir el carácter nulo

            printf("%s %s %s \n\n\n", usuario.nombre, usuario.username, usuario.password);
            
              break;
        
          case 2:
              printf("Contraseña: ");
              scanf("%s", password);
              strncpy(usuario.password, password, sizeof(usuario.password) - 1);
              usuario.password[sizeof(usuario.password) - 1] = '\0'; // Añadir el carácter nulo
              break;
          case 3:
              printf("Tipo de usuario:\n");
              printf("[1] Administrador\n");
              printf("[2] Bodeguero\n");
              printf("[3] Vendedor\n");
              printf("[4] Cancelar\n");
              scanf("%i", &opcion2);
              switch (opcion2) {
                  case 1:
                      usuario.tipo = ADMINISTRADOR;
                      break;
                  case 2:
                      usuario.tipo = BODEGUERO;
                      break;
                  case 3:
                      usuario.tipo = VENDEDOR;
                      break;
                  case 4:
                      printf("Saliendo...\n");
                      printf("Saliste exitosamente\n");
                      break;
                  default:
                      printf("Saliendo...\n");
                      printf("Saliste exitosamente\n");
                      break;
              }
              break;
          case 4:
              printf("Saliendo...\n");
              printf("Saliste exitosamente\n");
              break;
          default:
              printf("Opción incorrecta.\n");
              printf("Saliendo...\n");
              printf("Saliste exitosamente\n");
              break;
      }

       // Busca el usuario en la lista y actualiza su información
        int posicion = -1;
        for (int i = 0; i < 10; i++) {
            if (strcmp(lista[i].username, usuario.username) == 0) {
                posicion = i;
                break;
            }
        }

        if (posicion != -1) {
            // Actualiza el usuario en la lista
          printf("usuario, nombre: %s %s\n\n", lista[posicion].nombre, lista[posicion].username);
          
            lista[posicion] = usuario;
          
            printf("usuario, nombre: %s %s", lista[posicion].nombre, lista[posicion].username);

            // Guarda la lista de usuarios actualizada en el archivo
            guardar_usuarios(lista, 10);
        } else {
            printf("Usuario no encontrado en la lista.\n");
        }
      
    } else {
        printf("ERROR. Usted no es administrador.\n");
    }
    return usuario;
}

struct Producto crear_producto(struct Usuario bodeguero, char nombre[20], float precio_compra, char marca[20], char codigo[10], struct Producto lista[]) {
    struct Producto p;
    int opcion2;

    if (bodeguero.tipo == BODEGUERO) {
        strncpy(p.nombre, nombre, sizeof(p.nombre));
        strncpy(p.marca, marca, sizeof(p.marca));
        strncpy(p.codigo, codigo, sizeof(p.codigo));
        p.precio_compra = precio_compra;

        printf("Tipo de producto:\n");
        printf("[1] Laptops\n");
        printf("[2] Teclados\n");
        printf("[3] Procesadores\n");
        printf("[4] Default\n");
        scanf("%i", &opcion2);

        switch (opcion2) {
            case 1:
                p.cat = LAPTOPS;
                break;

            case 2:
                p.cat = TECLADOS;
                break;

            case 3:
                p.cat = PROCESADORES;
                break;

            case 4:
                printf("Producto asignado como default\n");
                printf("Si desea cambiar la cat del producto, podrá hacerlo desde el menú\n");
                p.cat = DEFAULT;
                break;

            default:
                printf("Producto asignado como default\n");
                printf("Si desea cambiar la cat del producto, podrá hacerlo desde el menú\n");
                p.cat = DEFAULT;
                break;
        }

        // Aquí se guarda el producto en el arreglo

        // Guardar el nuevo usuario en la lista
        int existe = 0;
        int contador = 0;

        // Buscar un espacio vacío y verificar si el producto ya existe
        for (int i = 0; i < 20; i++) {
          printf("%s", lista[i].codigo);
            if (lista[i].nombre[0] != '\0') {
                contador++;
            }
            if (strcmp(lista[i].codigo, p.codigo) == 0) {
                existe = 1;
                break;
            }
        }

        if (existe == 0 && contador < 20) {
            // El usuario no existe y hay espacio vacío en el arreglo
            printf("producto anterior %s\n", lista[contador - 1].nombre);
            printf("producto nuevo %s\n", lista[contador].nombre);

            // Crear el nuevo usuario
            lista[contador] = p;
            contador++;
          
            // Guardar la lista de usuarios actualizada en el archivo
          guardarproductos(lista, contador);
          printf("Producto agregado exitosamente\n");

        } else {
            printf("El producto ya existe o la lista está llena.\n");
        }

        // Se guarda la lista de productos actualizada en el archivo
    } else {
        printf("ERROR. Usted no es bodeguero.\n");
    }
    return p;
}


struct Producto actualizar_producto(struct Usuario bodeguero, struct Producto producto, struct Producto lista[]) {
      int opcion;
      int opcion2;
      char nombre[20];
      float precio;
      char marca[20];

      if (bodeguero.tipo == BODEGUERO) {
          printf("Seleccione una categoría:\n");
          printf("[1] Nombre\n");
          printf("[2] Precio\n");
          printf("[3] Marca\n");
          printf("[4] Categoría\n");
          printf("[5] Cancelar\n");

          scanf("%i", &opcion);

          switch (opcion) {
              case 1:
                  printf("Nombre: ");
                  scanf("%s", nombre);
                  // Evita desbordamiento del buffer
                  strncpy(producto.nombre, nombre, sizeof(producto.nombre));
                  break;

              case 2:
                  printf("Nuevo Precio: ");
                  scanf("%f", &precio);
                  producto.precio_compra = precio;
                  break;

              case 3:
                  printf("Nueva Marca: ");
                  scanf("%s", marca);
                  strncpy(producto.marca, marca, sizeof(producto.marca));
                  break;

              case 4:
                  printf("Categorías disponibles:\n");
                  printf("[1] Laptops\n");
                  printf("[2] Teclados\n");
                  printf("[3] Procesadores\n");
                  printf("[4] Default\n");
                  printf("[5] Cancelar\n");
                  scanf("%i", &opcion2);
                  switch (opcion2) {
                      case 1:
                          producto.cat = LAPTOPS;
                          break;

                      case 2:
                          producto.cat = TECLADOS;
                          break;

                      case 3:
                          producto.cat = PROCESADORES;
                          break;

                      case 4:
                          producto.cat = DEFAULT;
                          break;

                      case 5:
                          printf("Saliendo...\n");
                          printf("Saliste exitosamente\n");
                          break;

                      default:
                          printf("Saliendo...\n");
                          printf("Saliste exitosamente\n");
                          break;
                  }
                  break;

              case 5:
                  printf("Saliendo...\n");
                  printf("Saliste exitosamente\n");
                  break;

              default:
                  printf("Opción incorrecta.\n");
                  printf("Saliendo...\n");
                  printf("Saliste exitosamente\n");
                  break;
          }

         // Busca el usuario en la lista y actualiza su información
          int posicion = -1;
          for (int i = 0; i < 10; i++) {
              if (strcmp(lista[i].codigo, producto.codigo) == 0) {
                  posicion = i;
                  break;
              }
          }

          if (posicion != -1) {
              // Actualiza el usuario en la lista
            printf("usuario, nombre: %s %s\n\n", lista[posicion].codigo, lista[posicion].codigo);

              lista[posicion] = producto;

              printf("usuario, nombre: %s %s", lista[posicion].codigo, lista[posicion].codigo);

              // Guarda la lista de usuarios actualizada en el archivo
              guardarproductos(lista, 20);
            
      } else {
          printf("ERROR. Usted no es bodeguero.\n");
      }
      return producto;
  }
}

struct Venta vender_producto(struct Usuario vendedor, struct Producto producto, struct Local *sucursal, struct Venta lVentas[]) {
    struct Venta nuevaventa;
    time_t tiempo;

    if (vendedor.tipo == VENDEDOR) {
        nuevaventa.local = *sucursal;
        nuevaventa.vendedor = vendedor;
        nuevaventa.producto = producto;

        // Obtener la fecha y hora actual
        time(&tiempo);
        nuevaventa.fecha = *localtime(&tiempo);

        // Establecer el precio de venta
      printf("Precio de venta: ");
      float precio_venta;
      scanf("%f", &precio_venta);
      nuevaventa.precio_venta = precio_venta; // Aquí debes establecer el precio de venta adecuado

        struct Bodega bodega = sucursal->bodega;
        bodega.inventario -= 1;

        printf("Venta exitosa\n");

        // Guardar la venta en la lista de ventas

      int num = 0;

      // Recorre la lista de ventas hasta encontrar una venta con fecha NULL
      for (int i = 0; i < 50; i++){
        if (lVentas[i].precio_venta == 0.0f) {
            num = i;
        }
      }

        lVentas[num] = nuevaventa;

        // Guardar la venta en el archivo
        guardar_ventas(lVentas);
    } else {
        printf("Usted no es vendedor\n");
    }

    return nuevaventa;
}

// guardar y cargar usuarios

void guardar_usuarios(struct Usuario lUsuarios[], int numUsuarios) {
    FILE *archivo = fopen("usuarios.txt", "w");
    if (archivo != NULL) {
        for (int i = 0; i < numUsuarios; i++) {

          printf("%s %s %s \n\n", lUsuarios[i].nombre, lUsuarios[i].password, lUsuarios[i].username);
          
          if (lUsuarios[i].username[0] != '\0' && lUsuarios[i].nombre[0] != '\0' && lUsuarios[i].password[0] != '\0'){
              fprintf(archivo, "%d %s %s %s\n", lUsuarios[i].tipo, lUsuarios[i].nombre, lUsuarios[i].username, lUsuarios[i].password);
          }
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}


int cargar_usuarios(struct Usuario lUsuarios[]) {
    FILE *archivo = fopen("usuarios.txt", "r");
    int numUsuarios = 0;
    if (archivo != NULL) {
        while (fscanf(archivo, "%d %s %s %s\n", &lUsuarios[numUsuarios].tipo, lUsuarios[numUsuarios].nombre, lUsuarios[numUsuarios].username, lUsuarios[numUsuarios].password) != EOF) {
            numUsuarios++;
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo.\n");
    }
    return numUsuarios;
}


// guardar y cargar productos

void guardarproductos(struct Producto lProductos[], int numProductos) {
    FILE *archivo = fopen("productos.txt", "w");
    if (archivo != NULL) {
        for (int i = 0; i < numProductos; i++) {
            if (lProductos[i].codigo[0] != '\0' && lProductos[i].nombre[0] != '\0' && lProductos[i].precio_compra != 0 && lProductos[i].marca[0] != '\0'){
              fprintf(archivo, "%s %s %s %d %.2f\n", lProductos[i].nombre, lProductos[i].marca,
                      lProductos[i].codigo, lProductos[i].cat, lProductos[i].precio_compra);
            }
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo de productos.\n");
    }
}

int cargar_productos(struct Producto lProductos[]) {
    FILE *archivo = fopen("productos.txt", "r");
    int numProductos = 0;

    if (archivo != NULL) {
        while (fscanf(archivo, "%s %s %s %d %f\n", lProductos[numProductos].nombre,
                      lProductos[numProductos].marca, lProductos[numProductos].codigo,
                      &lProductos[numProductos].cat, &lProductos[numProductos].precio_compra) != EOF) {
            numProductos++;
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo de productos.\n");
    }
    return numProductos;
}


void guardar_ventas(struct Venta lVenta[]) {
    FILE *archivo = fopen("ventas.txt", "w");
    if (archivo != NULL) {
        for (int i = 0; i < 50; i++) {

          if (lVenta[i].precio_venta > 0.0f && lVenta[i].local.nombre[0] != '\0' && lVenta[i].vendedor.nombre[0] != '\0' && lVenta[i].producto.nombre[0] != '\0') {
              fprintf(archivo, "%s %s %s %d %.2f\n", lVenta[i].local.nombre, lVenta[i].vendedor.username,
                      asctime(&lVenta[i].fecha), lVenta[i].producto.cat, lVenta[i].precio_venta);
          }
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo de ventas para escritura.\n");
    }
}

int cargar_ventas(struct Venta lVenta[]) {
    FILE *archivo = fopen("ventas.txt", "r");
    int numVentas = 0;

    if (archivo != NULL) {
        while (fscanf(archivo, "%s %s %s %d %f\n", lVenta[numVentas].local.nombre, lVenta[numVentas].vendedor.username,
                      asctime(&lVenta[numVentas].fecha), &lVenta[numVentas].producto.cat, &lVenta[numVentas].precio_venta) != EOF) {
            numVentas++;
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo de ventas para lectura.\n");
    }

    return numVentas;
}