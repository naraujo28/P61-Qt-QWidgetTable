#ifndef PERSONADIALOG_H
#define PERSONADIALOG_H

#include <QDialog>

namespace Ui {
class PersonaDialog;
}

class PersonaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonaDialog(QWidget *parent = nullptr);
    ~PersonaDialog();

    QString nombre();
    QString apellido();
    QString telefono();
    QString email();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PersonaDialog *ui;
};

#endif // PERSONADIALOG_H
