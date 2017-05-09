#include "GuiWindow.hpp"

#include "gnuplot-iostream.h"

#include <glog/logging.h>

#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>

using Poco::Data::Keywords::into;
using Poco::Data::Keywords::range;
using Poco::Data::Statement;
using Poco::Data::Session;

using namespace std;

GuiWindow::GuiWindow(int argc, char ** argv) : _kit(argc, argv) {

    Gtk::HBox * ptrHBox = Gtk::manage(new Gtk::HBox);

    // image panel
    ptrHBox->pack_start(_image, Gtk::PACK_SHRINK);

    // TODO
    todoPlot();
    _image.set("out_todo.png");

    // config panel
    Gtk::VBox * ptrVBox = Gtk::manage(new Gtk::VBox);
    ptrHBox->pack_start(*ptrVBox);

    Gtk::Button * ptrButtonQuit 
        = Gtk::manage(new Gtk::Button("  Quit  "));
    ptrVBox->pack_start(*ptrButtonQuit, Gtk::PACK_SHRINK);

    // signals
    ptrButtonQuit->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));

    // main window
    _window.add(*ptrHBox);
    _window.show_all();
}

void GuiWindow::run() {
    _kit.run(_window);
}

// TODO
void GuiWindow::todoPlot() {

    // get data 
    Poco::Data::SQLite::Connector::registerConnector();
    Poco::Data::Session session("SQLite", "data.db");
    vector<pair<string,double>> data;
    string stationName;
    double stationY;
    std::locale oldLoc = std::locale::global(std::locale("C"));
    Statement select(session);
    select << "select name, y \
        from station \
        limit 20",
           into(stationName), into(stationY), range(0, 1); 
    while (not select.done()) {
        select.execute();
        data.push_back(make_pair(stationName, stationY));
    }
    std::locale::global(oldLoc);
    LOG(INFO) << data.size() << " row(s) read\n";
    LOG(INFO) << "first row: " << data.front().first << " " 
        << data.front().second << endl;

    // plot data
    Gnuplot gp;
    gp << "set output 'out_todo.png' \n";
    gp << "set terminal png size 800,600 \n";
    gp << "set style fill solid border -1 \n";
    gp << "set grid ytics \n";
    gp << "set boxwidth 0.8 \n";
    gp << "set xtics rotate by -45 \n";
    gp << "plot " << gp.file1d(data, "out_todo.csv") 
        << " using 2:xtic(1) lc rgb 'green' with boxes notitle \n";
}

