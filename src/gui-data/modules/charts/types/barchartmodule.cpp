//
// Created by chess on 6/5/2021.
//
#include "main.h"

BarChartModule::BarChartModule(const BarChartModule::Builder &builder) {
    this->axisConstraint = builder.axisConstraint;
    this->title = builder.title;
    this->refreshTime = builder.refreshTime;
    this->seriesList = builder.seriesList;
}

nlohmann::json BarChartModule::getData() {
    nlohmann::json data;

    // Add each data series
    for (auto const &keyValue : seriesList) {
        data[keyValue.first] = keyValue.second();
    }

    return data;
}

nlohmann::json BarChartModule::getConfiguration() {
    nlohmann::json data;

    data["module-type"] = "barchart";
    data["refresh-rate"] = refreshTime;
    data["min-range"] = axisConstraint.first;
    data["max-range"] = axisConstraint.second;

    std::vector<std::string> seriesNames;

    // Add each map name (chart name)
    for (auto const &keyValue : seriesList) {
        seriesNames.push_back(keyValue.first);
    }

    data["series-names"] = seriesNames;

    return data;
}

std::shared_ptr<BarChartModule> BarChartModule::Builder::build() {
    return std::make_shared<BarChartModule>(*this);
}
