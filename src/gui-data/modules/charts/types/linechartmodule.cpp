//
// Created by chess on 5/31/2021.
//

#include "main.h"

LineChartModule::LineChartModule(const LineChartModule::Builder &builder) {
    this->axisConstraint = builder.axisConstraint;
    this->title = builder.title;
    this->scroll = builder.scroll;
    this->refreshTime = builder.refreshTime;
    this->seriesList = builder.seriesList;
}

nlohmann::json LineChartModule::getData() {
    nlohmann::json data;

    // Add each data series
    for (auto const &keyValue : seriesList) {
        data[keyValue.first] = keyValue.second();
    }

    return data;
}

nlohmann::json LineChartModule::getConfiguration() {
    nlohmann::json data;

    data["module-type"] = "linechart";
    data["scroll"] = scroll;
    data["min-range"] = axisConstraint.first;
    data["max-range"] = axisConstraint.second;
    data["refresh-rate"] = refreshTime;

    std::vector<std::string> seriesNames;

    // Add each map name (chart name)
    for (auto const &keyValue : seriesList) {
        seriesNames.push_back(keyValue.first);
    }

    data["series-names"] = seriesNames;

    return data;
}

std::shared_ptr<LineChartModule> LineChartModule::Builder::build() {
    return std::make_shared<LineChartModule>(*this);
}

LineChartModule::Builder LineChartModule::Builder::withAutoScroll() {
    scroll = true;

    return *this;
}
