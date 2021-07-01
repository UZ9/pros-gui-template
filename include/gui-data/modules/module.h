//
// Created by chess on 5/30/2021.
//

#include "main.h"
#include "gui-data/lib/json/json.hpp"

class Module {
public:
    /**
     * Retrieves the current name of the module, configured in the Builder
     *
     * @return The name of the module
     */
    std::string getTitle();

    /**
     * Retrieves the current data from modules to send to the C# backend
     * @return Serialized data in the form of JSON
     */
    virtual nlohmann::json getData() = 0;

    /**
     * Retrieves the configuration file, holding the necessary information for the creation of modules
     * @return Serialized configuration data in the form of JSON
     */
    virtual nlohmann::json getConfiguration() = 0;

    // TODO: Uncomment this as soon as ModuleManager has finished
//    void registerModule(const ModuleManager& chartManager);

    template<class T, typename U>
    class Builder {
    public:
        std::string title;

        /**
         * Virtual method every Module implements to construct itself
         * @return A built Module
         */
        virtual std::shared_ptr<T> build() = 0;
    };
protected:
    std::string title;

};