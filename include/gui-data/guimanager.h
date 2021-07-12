//
// Created by BHWS Robotics on 4/20/2021.
//

#include "main.h"
#include <vector>

class GUIManager {
private:
    std::vector<VariableDataHandler*> variableData;
public:
    /**
     * Start the task sending data to the WestCore C# GUI named pipe
     */
    void startTask();

    /**
     * Signal the GUI to stop all debugging prints to the console.
     */
    void stopTask();

    /**
     * Adds a new DataHandler to be registered into the GUI.
     * @param dataHandler Either a Variable<T> or VariableGroup<T> object
     */
    void registerDataHandler(VariableDataHandler* dataHandler) {
        variableData.push_back(dataHandler);
    }
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
