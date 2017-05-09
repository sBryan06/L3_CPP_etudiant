#include "GuiWindow.hpp"

#include <glog/logging.h>

int main(int argc, char ** argv) {
    google::InitGoogleLogging("log_taxi");
    google::SetLogDestination(google::GLOG_INFO, "log_taxi");
    GuiWindow guiWindow(argc, argv);
    guiWindow.run();
    return 0;
}

