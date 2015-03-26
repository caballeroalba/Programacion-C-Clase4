#include <gtk/gtk.h>
#include <stdlib.h>
#include "principal_concesionario.h"



static void entry_Submit(GtkButton *button, gpointer data)
{
    GtkWidget **entry= (GtkWidget **) data;
    GtkWidget *entry_nombre=entry[0];
    printf("el nombre es : %s\n",gtk_entry_get_text((GtkEntry *) entry_nombre));
    struct concesionario *con;
    con=curso_concesionario_alloc();
    curso_concesionario_attr_set_str(con,CURSO_CONCESIONARIO_ATTR_DUENO,gtk_entry_get_text((GtkEntry *) entry_nombre));
    if(con==NULL)
        return;
    
    principal_concesionario((GtkEntry *)entry_nombre, con);
}

int main (int argc, char *argv[])
{
	GtkWidget *ventana;
    GtkWidget *nombre_concesionario;
    GtkWidget *hbox;
    GtkWidget *vbox;
    GtkWidget *boton_nombre;
    GtkWidget **entrada_nombre;
    entrada_nombre=malloc(1 * sizeof(GtkWidget));
	gtk_init (&argc, &argv);
    

    hbox=gtk_hbox_new(TRUE,5);
    vbox=gtk_vbox_new(TRUE,5);
    nombre_concesionario=gtk_label_new("Nombre del dueño");
    entrada_nombre[0]=gtk_entry_new();
    boton_nombre=gtk_button_new_with_label("Aceptar");
    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)ventana, "Hola mundo");
    gtk_box_pack_start((GtkBox *) vbox,hbox,TRUE,TRUE,0);
	gtk_box_pack_start((GtkBox *) hbox, nombre_concesionario,TRUE,TRUE,0);
    gtk_box_pack_start((GtkBox *) hbox,entrada_nombre[0],TRUE,TRUE,0);
    gtk_box_pack_start((GtkBox *) vbox, boton_nombre,TRUE,TRUE,0);
    gtk_container_add((GtkContainer *) ventana, vbox);
    
    
    g_signal_connect((GObject *) boton_nombre,"clicked",(GCallback) entry_Submit,
            (gpointer) entrada_nombre);

    gtk_widget_show_all(ventana);
    gtk_widget_show(nombre_concesionario);

    
	gtk_main();
	return 0;
}
