# pros-gui-template
PROS template for the C# GUI project. 
![image](https://user-images.githubusercontent.com/36551149/124071337-c8e35c80-da04-11eb-999c-a1ccbff2fd30.png)

# Using Grafana
The Grafana version of this template is currently nonexistent, but will be added as soon as the [pros-grafana](https://github.com/BWHS-Robotics/pros-grafana) plugin is stable. 

# Installation Steps
### Using the pre-built template
Under the **Releases** panel of the repository you can find all of the uploaded zip versions for the project. Download the version you want and save it within the root of your PROS project. With the zip in the root of your project, use ``prosv5 c fetch .`` to install the template into your local depot, and add it to your existing PROS project using ``pros c apply guilib --force-apply``. Because the template is now in your local PROS depot, the template can be installed in any compatible PROS project without the need of redownloading or fetching the `guilib` package.
# Usage
## Module Builder System
In order to make GUI creation as straightforward as possible, visualizations are grouped together in prebuilt templates called ``Module``s. All of the current ``Module`` types and their initialization can be seen below. 
### LineChartModule
```cpp
auto motorEfficiency = LineChartModule::Builder()
        // Set the title of the chart
        .withTitle("Efficiency") 
        // The addSeries method will take in a series name and std::function to track
        .addSeries("Front Left Motor", [=] { return leftFront.get_efficiency(); }) 
        // Constrains the Y axis between the values -500 (min) and 500 (max)
        .withYConstraints({-500, 500})
        // If enabled, the chart will automatically scroll to keep up with data as it is streamed in. 
        .withAutoScroll()
        // The refresh time will determine the interval at which the module will send its data to the GUI. 
        .withRefreshTime(200)
        .build();
```
### BarChartModule
```cpp
auto barChart = BarChartModule::Builder()
        // Same as the LineChartModule
        .withTitle("Example Bar Chart")
        // Same as the LineChartModule
        .addSeries("Front Left Motor", [=] { return leftFront.get_temperature(); })
        // Same as the LineChartModule
        .withRefreshTime(200)
        .build();
```
### OdometryModule
```cpp
// In this example, getX(), getY(), and getHeading() would be substituted for whatever 
// you use to retrieve your robot's position. 
auto odomModule = OdometryModule::Builder()
        // Allows the robot's position to be sent to the GUI given access to its x, y, and heading
        .withPositionTracker([=] { return tuple<double, double, double>(getX(), getY(), getHeading()); })
        .build();
```
## GUIManager
### Registering Modules
In order to register modules to the GUI, they must be passed into a ``GUIManager``, as seen below:
```cpp
// Initialize GUIManager
GUIManager manager;

auto velocityGraph = LineChartModule::Builder()
        .withTitle("Voltage")
        .addSeries("Front Left Motor", [=] { return leftFront.get_actual_velocity(); })
        .withYConstraints({-300, 300})
        .withAutoScroll()
        .withRefreshTime(200)
        .build();

// Register module to GUIManager
manager.registerModule(velocityGraph);
```
### Starting the data transmission 
Finally, to begin piping the module data to the GUI the GUIManager must start its send task:
```cpp
manager.startTask();
```
## Testing 
To make sure the C++ side is correctly working, you can use ``pros terminal`` to spit out all of the data trying to be sent to the GUI. If a module is registered correctly there should be something under the lines of this image:

![image](https://user-images.githubusercontent.com/36551149/124072257-25934700-da06-11eb-940b-26cfa30c1d65.png)

where the names might be different depending on what modules you have registered and their associated names.

## Using the GUI
Now that the PROS code has been verified, we can begin sending data to the GUI. To do this, make sure you have [installed the pros-cli fork](https://github.com/BWHS-Robotics/pros-cli), and run the command ``pros gui_data``. The bundled GUI should now begin running and will connect to the PROS CLI. Data will begin to flow through into the GUI as soon as the program on the V5 brain has been started.

