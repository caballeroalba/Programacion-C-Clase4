#include "ver_coches.h"
#include <gtk/gtk.h>
struct datos{

    gpointer data;
    struct concesionario *con;
    GtkWidget *ven;
};
static void save(GtkButton *button, struct datos *datos);

static void cancelar(GtkButton *button, GtkWidget *ven);



struct coche *crear_coche(struct concesionario *con);
