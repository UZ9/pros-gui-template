//
// Created by chess on 5/31/2021.
//

#include "main.h"
#include "gui-data/lib/json/json.hpp"


class LineChartModule : public ChartModule {
public:
    nlohmann::json getData() override;

    nlohmann::json getConfiguration() override;

    class Builder : public ChartModule::Builder<LineChartModule, LineChartModule::Builder> {
    public:
        /**
         * Determines whether the chart should auto-scroll when points begin to leave its render plane.
         */
        LineChartModule::Builder withAutoScroll();

        std::shared_ptr<LineChartModule> build() override;

        bool scroll = false;
    };

    explicit LineChartModule(const LineChartModule::Builder& builder);
protected:
    bool scroll = false;
};