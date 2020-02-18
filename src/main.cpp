#include "nanoplot.h"
#include "dataloader.h"
#include "processdata.h"
#include "constants.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string path = "";
    const int TESTING = argc-1;
    if(TESTING)
    {
        path = argv[1];
    }
    else
    {
        path = "../data/original/force_curve.csv";
    }

    DataLoader loader(path);

    ProcessData process(loader.getXValues(), loader.getYValues());
    Nanoplot plot(nullptr,
                  process.getXValues(), process.getYValues(),
                  process.getXRange(), process.getYRange());

    plot.setFixedSize(2*X_AXIS_SHIFT + PLOT_WIDTH, 2*X_AXIS_SHIFT + PLOT_HEIGHT);

    plot.show();
    return a.exec();
}
