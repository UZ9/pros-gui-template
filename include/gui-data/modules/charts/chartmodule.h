//
// Created by chess on 5/30/2021.
//

#include "main.h"

class ChartModule : public Module {
public:
    template<class T, typename U>
    class Builder : public Module::Builder<T, U> {
    public:
        std::pair<double, double> axisConstraint;
        std::map<std::string, std::function<double()>> seriesList;
        int refreshTime = 100;

        /**
         * Adds a series to the chart with a given key (shown in the top right of the GUI)
         * @param ititle The name of the series
         * @param ifunc Any function (including lambdas) returning a double
         */
        U &addSeries(const std::string &ititle, const std::function<double()> &ifunc) {
            this->seriesList[ititle] = ifunc;

            return static_cast<U &>(*this);
        }

        /**
         * Sets the title of the chart to a given value
         *
         * @param ititle The title of the hcart
         */
        U &withTitle(const std::string &ititle) {
            this->title = ititle;

            return static_cast<U &>(*this);
        }

        /**
         * Sets the Y-axis constraints for a particular chart.
         *
         * @param axisConstraint The min, max values to zoom
         */
        U &withYConstraints(std::pair<double, double> iaxisConstraint) {
            axisConstraint = iaxisConstraint;

            return static_cast<U &>(*this);
        }

        /**
         * Sets the refresh time for the visualization to be updated.
         * @param milleseconds The interval between refreshes in milliseconds
         */
        U &withRefreshTime(int milleseconds) {
            refreshTime = milleseconds;

            return static_cast<U &>(*this);
        }

    };

protected:
    std::pair<double, double> axisConstraint;
    std::map<std::string, std::function<double()>> seriesList;
    int refreshTime = 100;


};