//
// Created by BHWS Robotics on 4/20/2021.
//

#include "main.h"
#include <vector>

class GUIManager {
private:
    std::vector<std::shared_ptr<Module>> modules;
public:
    /**
     * Start the task sending data to the WestCore C# GUI named pipe
     */
    void startTask();

    /**
     * Signal the GUI to stop all debugging prints to the console.
     */
    void stopDebugging();

    /**
     * Registers a chart to WestCore C# GUI application
     * @param chart the chart will be registered
     */
    void registerModule(const std::shared_ptr<Module>& module);
private:
    bool alive;

    /**
     * Private task that utilizes all of the currently registered tasks and sends them to the WestCore C# GUI named pipe
     */
    void sendData();

    /**
     * Sends the needed configuration files for initially setting up charts
     *
     * Data such as y-min, y-max, and title are all sent through this method at the beginning of startTask().
     */
    void sendConfiguration();

};
