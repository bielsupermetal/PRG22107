#include "ocarinahero.h"
#include <QApplication>

OcarinaHero * game;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    game = new OcarinaHero();
    game->show();

    return app.exec();
}
