//
// Created by chess on 6/1/2021.
//

#include "main.h"
#include "gui-data/lib/json/json.hpp"

class OdometryModule : public Module {
public:
    nlohmann::json getData() override;

    nlohmann::json getConfiguration() override;

    class Builder : public Module::Builder<OdometryModule, OdometryModule::Builder> {
    public:
        /**
         * Sets the position tracker for the OdometryModule. In order for the module to send where the robot is
         * currently at, an std::tuple<double, double, double> is used to retrieve the x, y, and heading (int degrees) at any given time.
         * @param positionTracker The function tracking the position and heading of the robot
         */
        OdometryModule::Builder
        withPositionTracker(const std::function<std::tuple<double, double, double>()> &positionTracker);

        std::shared_ptr<OdometryModule> build() override;

        std::function<std::tuple<double, double, double>()> positionTracker;
    };

    explicit OdometryModule(const OdometryModule::Builder &builder);

protected:
    std::function<std::tuple<double, double, double>()> positionTracker;
};
