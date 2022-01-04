#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    // Conectar el dial de Cent con el Slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    // Conectar el dial de Fharenheit con el Slot de esta clase
    connect(ui->inFhar, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    // Conectar el dial de Kelvin con el Slot de esta clase
    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2centFhar(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int cent)
{
    if(ui->inCent->hasFocus()){
        //qDebug() << i; [Verificar que este funcionando bien]
        int fhar= (cent*9.0/5)+32;
        // Celcios a Fharenheit
        ui->inFhar->setValue(fhar); //[Setiar Diales]
        // Celcios a Kelvin
        int ck= cent+273;
        ui->inKel->setValue(ck);
    }
}

void Principal::fahr2cent(int i)
{
    if(ui->inFhar->hasFocus()){ // hasFocus[Cuando un usuario esta sobre un control]
        // Fharenheit a Celcios
        int c= (i-32)*5.0/9;
        ui->inCent->setValue(c);
        // Fharenheit a Kelvin
        int fk= (((i-32)*5.0/9)+273);
        ui->inKel->setValue(fk);
    }
    /* Mostrar en el visualizador
    ui->outFhar->display(fahr);*/
}

void Principal::kel2centFhar(int i)
{
    if(ui->inKel->hasFocus()){
        // Kelvin a Celcios
        int kc= (i-273);
        ui->inCent->setValue(kc);
        // Kelvin a Fharenheit
        int kf= (((i-273)*9.0/5)+32);
        ui->inFhar->setValue(kf);
    }
}
