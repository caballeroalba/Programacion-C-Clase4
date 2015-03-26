
#include "crear_coche.h"

#include <gtk/gtk.h>

static void crear(GtkButton *button, struct concesionario *con);


static void ver(GtkButton *button,struct concesionario *con);


int principal_concesionario (GtkEntry * dueno, struct concesionario *con);
