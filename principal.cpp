#include "principal.h"
#include "ui_principal.h"
#include "personadialog.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    setWindowTitle("Agenda telefónica");
    // Configurar la tabla
    ui->tblLista->setColumnCount(4);
    QStringList titulo;
    titulo << "Nombre" << "Apellido" << "Teléfono" << "E-mail";
    ui->tblLista->setHorizontalHeaderLabels(titulo);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_btnAgregar_clicked()
{
    // Crear y mostrar el dialogo
    PersonaDialog pd(this);
    pd.setWindowTitle("Agregar contacto");
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar los datos ingresados
    QString nombre = pd.nombre();
    QString apellido = pd.apellido();
    QString telefono = pd.telefono();
    QString email = pd.email();
    //Agregar a la tabla
    int fila = ui->tblLista->rowCount();
    ui->tblLista->insertRow(fila);
    ui->tblLista->setItem(fila, NOMBRE, new QTableWidgetItem(nombre));
    ui->tblLista->setItem(fila, APELLIDO, new QTableWidgetItem(apellido));
    ui->tblLista->setItem(fila, TELEFONO, new QTableWidgetItem(telefono));
    ui->tblLista->setItem(fila, EMAIL, new QTableWidgetItem(email));

}

