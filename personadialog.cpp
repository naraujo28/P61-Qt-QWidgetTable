#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

QString PersonaDialog::nombre()
{
    return ui->inNombre->text();
}

QString PersonaDialog::apellido()
{
    return ui->inApellido->text();
}

QString PersonaDialog::telefono()
{
    return ui->inTelefono->text();
}

QString PersonaDialog::email()
{
    return ui->inEmail->text();
}

void PersonaDialog::on_buttonBox_accepted()
{
    accept();
}


void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

