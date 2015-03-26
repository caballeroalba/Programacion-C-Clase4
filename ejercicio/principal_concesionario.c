#include "principal_concesionario.h"

static void crear(GtkButton *button, struct concesionario *con)
{

    struct coche *c;
    c=crear_coche(con);
    

}

static void ver(GtkButton *button,struct concesionario *con)
{
    if(con==NULL)
        return;
    struct coche *c=curso_concesionario_attr_get_coche(con,CURSO_CONCESIONARIO_ATTR_COCHE,0);
    if(c==NULL)
        return;
    printf("el coches es:%s\n",curso_coche_attr_get_str(c,CURSO_COCHE_ATTR_MATRICULA));
    ver_coches(con);
}


int principal_concesionario (GtkEntry * dueno, struct concesionario *con)
{
    GtkWidget *ventana;
    GtkWidget *nombre_concesionario;
    GtkWidget *hbox;
    GtkWidget *vbox;
    GtkWidget *boton_crear;
    GtkWidget *boton_ver;

    
    
    ventana=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    nombre_concesionario=gtk_label_new(gtk_entry_get_text((GtkEntry *) dueno));
    hbox=gtk_hbox_new(TRUE,5);
    vbox=gtk_vbox_new(TRUE,5);
    boton_crear=gtk_button_new_with_label("Crear coche");
    boton_ver=gtk_button_new_with_label("Ver cochces");
    
    gtk_window_set_title((GtkWindow *) ventana, "Principal concesionario");
    gtk_box_pack_start((GtkBox *) vbox, nombre_concesionario,TRUE,TRUE,0);
    gtk_box_pack_start((GtkBox *) vbox, hbox, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) hbox, boton_crear, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) hbox, boton_ver, TRUE, TRUE, 0);
    gtk_container_add((GtkContainer *) ventana, vbox);


    g_signal_connect((GObject *) boton_crear, "clicked", (GCallback) crear, con);
    g_signal_connect((GObject *) boton_ver, "clicked", (GCallback) ver, con);
    gtk_widget_show_all(ventana);

    return 0;

}
