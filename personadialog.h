#ifndef PERSONADIALOG_H
#define PERSONADIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "persona.h"

namespace Ui {
class PersonaDialog;
}

class PersonaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonaDialog(QWidget *parent = nullptr);
    ~PersonaDialog();
    void set_datos(QString nombre, QString apellido, QString telf, QString email);
    Persona *persona() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PersonaDialog *ui;
    Persona *m_persona;
    bool validarEmail(QString email);
    bool validarTelf(QString telf);
    bool validarTexto(QString texto);
};

#endif // PERSONADIALOG_H
