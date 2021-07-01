//
// Created by chess on 6/1/2021.
//

#include "gui-data/lib/json/json.hpp"

#include "main.h"


OdometryModule::OdometryModule(const OdometryModule::Builder &builder) {
    this->positionTracker = builder.positionTracker;
    title = "odommodule";
}

nlohmann::json OdometryModule::getData() {
    nlohmann::json data;

    std::tuple<double, double, double> currentPosition = positionTracker();

    data["x"] = std::get<0>(currentPosition);
    data["y"] = std::get<1>(currentPosition);
    data["heading"] = std::get<2>(currentPosition);

    return data;
}

nlohmann::json OdometryModule::getConfiguration() {
    nlohmann::json data;

    data["module-type"] = "odometry";

    return data;
}



OdometryModule::Builder
OdometryModule::Builder::withPositionTracker(const std::function<std::tuple<double, double, double>()> &ipositionTracker) {
    this->positionTracker = ipositionTracker;

    return *this;
}

std::shared_ptr<OdometryModule> OdometryModule::Builder::build() {
    return std::make_shared<OdometryModule>(*this);
}
