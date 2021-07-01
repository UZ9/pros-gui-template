//
// Created by chess on 6/5/2021.
//

#include "main.h"
#include "gui-data/lib/json/json.hpp"


class BarChartModule : public ChartModule {
public:
    nlohmann::json getData() override;

    nlohmann::json getConfiguration() override;

    class Builder : public ChartModule::Builder<BarChartModule, BarChartModule::Builder> {
    public:
        std::shared_ptr<BarChartModule> build() override;
    };

    explicit BarChartModule(const BarChartModule::Builder& builder);
protected:
};