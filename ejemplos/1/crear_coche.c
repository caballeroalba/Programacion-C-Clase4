#include "crear_coche.h"


static void save(GtkButton *button, struct datos *datos){
    GtkWidget **entry=(GtkWidget **) datos->data;
    GtkWidget *marca=entry[0];
    GtkWidget *matricula=entry[1];
    GtkWidget *gama=entry[2];
   
    
    struct coche *c;
    c=curso_coche_alloc();
    curso_coche_attr_set_str(c,CURSO_COCHE_ATTR_MATRICULA, 
                        gtk_entry_get_text((GtkEntry *) matricula));
    curso_coche_attr_set_str(c,CURSO_COCHE_ATTR_MARCA,gtk_entry_get_text((GtkEntry *) marca));
    
    curso_concesionario_attr_set_coche(datos->con,CURSO_CONCESIONARIO_ATTR_COCHE,c);   
    gtk_widget_destroy(datos->ven);  

}

static void cancelar(GtkButton *button, GtkWidget *ven){

   gtk_widget_destroy(ven); 
}




struct coche *crear_coche(struct concesionario *con)
{
    GtkWidget *ventana;
    GtkWidget *hbox_marca;
    GtkWidget *hbox_matricula;
    GtkWidget *hbox_gama;
    GtkWidget *vbox;
    GtkWidget *label_marca;
    GtkWidget *label_matricula;
    GtkWidget *label_gama;
    GtkWidget **entradas;
    GtkWidget *boton_guardar;
    GtkWidget *boton_cancelar;
    entradas=malloc(3  * sizeof(GtkWidget));
    GtkWidget *entry_marca,*entry_matricula, *entry_gama;

    entry_marca=gtk_entry_new();
    entry_matricula=gtk_entry_new();
    entry_gama=gtk_entry_new();
    entradas[0]=entry_marca;
    entradas[1]=entry_matricula;
    //entradas[2]=entry_gama;
    ventana=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    vbox=gtk_vbox_new(TRUE,5);
    hbox_marca=gtk_hbox_new(TRUE,5);
    hbox_matricula=gtk_hbox_new(TRUE,5);
    hbox_gama=gtk_hbox_new(TRUE,5);
    label_marca=gtk_label_new("Marca");
    label_matricula=gtk_label_new("Matricula");
    label_gama=gtk_label_new("Gama");
    boton_guardar=gtk_button_new_with_label("Guardar");
    boton_cancelar=gtk_button_new_with_label("Cancelar");

    gtk_window_set_title((GtkWindow *) ventana, "Nuevo coche");
    gtk_box_pack_start((GtkBox *) vbox ,hbox_marca, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) vbox, hbox_matricula, TRUE, TRUE, 0);
   // gtk_box_pack_start((GtkBox *) vbox, hbox_gama, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) vbox, boton_guardar, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) vbox, boton_cancelar, TRUE, TRUE, 0);
    //gtk_container_add((GtkContainer *) ventana,vbox);
    gtk_box_pack_start((GtkBox *) hbox_marca, label_marca, TRUE,TRUE, 0);
    gtk_box_pack_start((GtkBox *) hbox_marca, entry_marca, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) hbox_matricula, label_matricula, TRUE, TRUE, 0);
    gtk_box_pack_start((GtkBox *) hbox_matricula, entry_matricula, TRUE, TRUE, 0);
   // gtk_box_pack_start((GtkBox *) hbox_gama, label_gama, TRUE, TRUE, 0);
   // gtk_box_pack_start((GtkBox *) hbox_gama, entry_gama, TRUE, TRUE, 0);
    gtk_container_add((GtkContainer *) ventana, vbox);
    
    
    struct datos *d;
    d=calloc(1, sizeof(struct datos *));
    d->data=entradas;
    d->con=con;
    d->ven=(GtkWidget *) ventana;
    g_signal_connect((GObject *) boton_guardar,"clicked", (GCallback) save, d);
    

    g_signal_connect((GObject *)boton_cancelar ,"clicked", (GCallback) cancelar ,(GObject *) ventana); 
    gtk_widget_show_all(ventana); 
     
   
    return 0;
}
