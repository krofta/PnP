#include "pnp_options.h"
#include "ui_pnp_options.h"

pnp_options::pnp_options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pnp_options)
{
    ui->setupUi(this);
}

pnp_options::~pnp_options()
{
    delete ui;
}
