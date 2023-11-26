#include <stdio.h>
#include "funciones.h"
#include <string.h>;

int main(void) {
  // contemplamos que actualmente tienen un local (sucursal) y se piensan abrir 2 más en un futuro
  struct Local sucursales [3];

  // contemplamos que actualmente se tiene una bodega y se piensa abrir una en un futuro
  struct Bodega bodegas[3];
  bodegas [0] = (struct Bodega){"Bodega 1", 1, 50};

  struct Producto lProductos[20];  
  
  int numProductosCargados = cargar_productos(lProductos);

  cargar_productos(lProductos);

  // guardamos la primera sucursal con su bodega
  sucursales[0] = (struct Local){"Local 1", bodegas[0]};

  // creamos usuario
  struct Usuario lUsuarios[10];

  cargar_usuarios(lUsuarios);
  
  struct Venta lVenta[50];
  cargar_ventas(lVenta);

  int opcion;
  char usuario [10];
  char password [10];
  struct Usuario u;

  while (opcion != 2) {

    printf("Inicio de sesión\n");
    printf("[1] Iniciar Sesión\n");
    printf("[2] Salir\n");

    scanf("%i", &opcion);

    // Menú
    switch (opcion) {
      case 1:
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contraseña: ");
        scanf("%s", password);
        int inicio_sesion = 0;

        for (int i = 0; i <= 10; i++) {
          if ((strcmp(lUsuarios[i].username, usuario) == 0) && (strcmp(lUsuarios[i].password, password) == 0)){
            inicio_sesion = 1;
            u = lUsuarios[i];
            break;

          } else{
            inicio_sesion = 0;

          }        
        }

        if (inicio_sesion){
          while (opcion != 6){
            printf("Menú\n");
            printf("[1] Crear usuario\n");
            printf("[2] Actualizar usuario\n");
            printf("[3] Crear producto\n");
            printf("[4] Actualizar producto\n");
            printf("[5] Vender producto\n");
            printf("[6] Cerrar sesión\n");
            scanf("%i", &opcion);

            switch (opcion) {
              struct Usuario usuario_nuevo;
              struct Usuario usuario_p;
              struct Producto p;
              char marca[20];
              char codigo[10];
              char nombre [20];
              char usuario [10];
              char password [10];

              case 1:
              {
                  printf("Nombre: ");
                  scanf("%s", nombre);
                  printf("Username: ");
                  scanf("%s", usuario);
                  printf("Password: ");
                  scanf("%s", password);
                  int existe = 0;
                  int contador = 0;

                  // Buscar un espacio vacío y verificar si el usuario ya existe
                  for (int i = 0; i < 10; i++) {
                      if (lUsuarios[i].username[0] != '\0') {
                          contador++;
                      }
                      if (strcmp(lUsuarios[i].username, usuario) == 0) {
                          existe = 1;
                          break;
                      }
                  }

                  if (existe == 0 && contador < 10) {
                      // El usuario no existe y hay espacio vacío en el arreglo

                      // Crear el nuevo usuario
                      struct Usuario usuario_nuevo = crear_usuario(u, nombre, usuario, password, lUsuarios);

                      // Copiar el nuevo usuario en el espacio vacío
                      lUsuarios[contador] = usuario_nuevo;
                  }

                  break;
              }

              case 2:
                {

                  printf("Lista de usuarios\n");

                  for (int i = 0; i < 10; i++) {
                      if (lUsuarios[i].username[0] != '\0') {
                          printf("[%i] %s\n", i, lUsuarios[i].username);
                      }
                  }

                  printf("Username: ");
                  scanf("%s", usuario);

                  int indice_usuario_encontrado = -1; // Inicializa la variable de índice a -1

                  for (int i = 0; i < 10; i++) {
                      if (strcmp(lUsuarios[i].username, usuario) == 0) {
                          // Se encontró un usuario con el mismo nombre de usuario
                          indice_usuario_encontrado = i;
                          break; // Sal del bucle una vez que se haya encontrado una coincidencia
                      }
                  }

                  if (indice_usuario_encontrado != -1) {
                      // Se encontró un usuario con el mismo nombre de usuario en 'lUsuarios'
                    
                      usuario_p = lUsuarios[indice_usuario_encontrado];

                      usuario_p = actualizar_usuario(u, lUsuarios[indice_usuario_encontrado], lUsuarios);

                      printf("Usuario actualizado exitosamente\n");

                  } else {
                      // No se encontró ningún usuario con el mismo nombre de usuario
                      printf("Usuario no encontrado en la lista.\n");
                  }

                  break;

              }

              case 3:
              {
                  float precio_compra = 0;
                  printf("Nombre del producto: ");
                  scanf("%s", nombre);
                  printf("Marca del producto: ");
                  scanf("%s", marca);
                  printf("Código del producto: ");
                  scanf("%s", codigo);
                  printf("Precio de compra: ");
                  scanf("%f", &precio_compra);

                  int existe = 0;
                  int contador = 0;

                  // Buscar un espacio vacío y verificar si el producto ya existe
                  for (int i = 0; i < 20; i++) {
                      if (lProductos[i].codigo[0] != '\0') {
                          contador++;
                      }
                      if (strcmp(lProductos[i].codigo, codigo) == 0) {
                          existe = 1;
                          break;
                      }
                  }

                  if (existe == 0 && contador < 20) {
                      // El producto no existe y hay espacio vacío en el arreglo

                      // Crear el nuevo producto
                      struct Producto p = crear_producto(u, nombre, precio_compra, marca, codigo, lProductos);

                      // Copiar el nuevo producto en el espacio vacío
                      lProductos[contador] = p;

                  }
                  else {
                      printf("El producto ya existe o la lista está llena.\n");
                  }

                  break;
              }

              case 4:
                {
                    printf("Lista de productos\n");

                    for (int i = 0; i < 10; i++) {
                        if (lProductos[i].codigo[0] != '\0') {
                            printf("[%i] Código: %s, Nombre: %s, Marca: %s\n", i, lProductos[i].codigo, lProductos[i].nombre, lProductos[i].marca);
                        }
                    }

                    printf("Código del producto a actualizar: ");
                    scanf("%s", codigo);

                    int indice_producto_encontrado = -1; // Inicializa el índice a -1

                    for (int i = 0; i < 10; i++) {
                        if (strcmp(lProductos[i].codigo, codigo) == 0) {
                            // Se encontró un producto con el mismo código
                            indice_producto_encontrado = i;
                            break; // Sal del bucle una vez que se haya encontrado una coincidencia
                        }
                    }

                    if (indice_producto_encontrado != -1) {
                        // Se encontró un producto con el mismo código en 'lProductos'
                        p = lProductos[indice_producto_encontrado];

                        struct Producto producto_actualizado = actualizar_producto(u, p, lProductos);

                        lProductos[indice_producto_encontrado] = producto_actualizado;

                        printf("Producto actualizado exitosamente\n");
                    } else {
                        // No se encontró ningún producto con el mismo código
                        printf("Producto no encontrado en la lista.\n");
                    }

                    break;
                }

              case 5:
              {
                for (int i = 0; i<50; i++){
                  printf("%f %s %s %s\n", lVenta[i].precio_venta , lVenta[i].local.nombre,lVenta[i].vendedor.nombre ,lVenta[i].producto.nombre);
                }
                
                int opcion_sucursal = 0;
                int opcion_producto = 0;

                // Muestra las opciones de sucursales y productos al usuario
                for (int i = 0; i < 3; i++) {
                    if (sucursales[i].nombre[0] != '\0') {
                        printf("[%d] %s\n", i + 1, sucursales[i].nombre);
                    }
                }

                // Solicita al usuario que elija una sucursal
                printf("Elige una sucursal (1-3): ");
                fflush(stdin); 
                scanf("%i", &opcion_sucursal);


                // Valida la elección del usuario
                if (opcion_sucursal < 1 || opcion_sucursal > 3) {
                    printf("Opción no válida.\n");
                    return 1;
                }

                printf("Productos disponibles:\n");
                for (int i = 0; i < 20; i++) {
                    if (lProductos[i].nombre[0] != '\0') {
                        printf("[%d] %s\n", i + 1, lProductos[i].nombre);
                    }
                }
                printf("Elige un producto (1-20): ");
                scanf("%i", &opcion_producto);

                if (opcion_producto < 1 || opcion_producto > 20) {
                    printf("Opción no válida.\n");
                    return 1;
                }

                int contador = 0;

                for (int i = 0; i < 20; i++) {
                    if (lVenta[i].precio_venta != 0) {
                        contador++;
                    }
                }



              struct Venta nuevaVenta = vender_producto(u, lProductos[opcion_producto - 1], &sucursales[opcion_sucursal - 1], lVenta);

              lVenta[contador] = nuevaVenta;
                
                break;
              }
            }

            }

          } else {
            printf("Credenciales incorrectas\n");

          }

          break;  
        }
    }

  }