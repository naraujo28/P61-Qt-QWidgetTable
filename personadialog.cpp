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

void PersonaDialog::set_datos(QString nombre, QString apellido, QString telf, QString email)
{
    ui->inNombre->setText(nombre);
    ui->inApellido->setText(apellido);
    ui->inTelefono->setText(telf);
    ui->inEmail->setText(email);
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();

    if(!validarTexto(nombre)){
        ui->inNombre->setToolTip("Nombre incorrecto, ingrese letras");
    }
    if(!validarTexto(apellido)){
        ui->inApellido->setToolTip("Apellido incorrecto, ingrese letras");
    }
    if(!validarTelf(telefono)){
        ui->inTelefono->setToolTip("Telefono incorrecto, ingrese numeros");
    }
    if(!validarEmail(email)){
        ui->inEmail->setToolTip("E-mail incorrecto");
    }


    if(!validarTexto(nombre) || !validarTexto(apellido) || !validarTelf(telefono) || !validarEmail(email)){
        QMessageBox::information(this, "Error", "Datos Erróneos o Incompletos");
        return;
    }

    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

bool PersonaDialog::validarEmail(QString email)
{
    if(email.isEmpty()){
        return false;
    }

      QRegExp patron ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return patron.exactMatch(email);
}

bool PersonaDialog::validarTelf(QString telf)
{
    if(telf.isEmpty() || telf.length()!=10){
        return false;
    }

    QChar auxiliar[10];

    for(int i = 0; i < 10; i++)
    {
        auxiliar[i] = telf[i];
    }

    for(int i = 0; i < 10; i++)
    {
        if(auxiliar[i].isDigit()==0){
            return false;
            break;
        }
    }
    return true;
}

bool PersonaDialog::validarTexto(QString texto)
{
    if(texto.isEmpty()){
        return false;
    }
    int tam = texto.length();
    QChar aux[tam];

    for(int i = 0; i < tam; i++)
    {
        aux[i] = texto[i];
    }

    for(int i = 0; i < tam; i++)
    {
        if(aux[i].isDigit()==1){
            return false;
            break;
        }
    }
    return true;
}
