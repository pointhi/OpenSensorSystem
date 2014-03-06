OpenSensorSystem
================

A tree based controll-system to work with sensors, based on xml and lua

**Licence:** GNU GPLv3

**work status:** pre Alpha, still in Developing

[![Build Status](https://travis-ci.org/pointhi/OpenSensorSystem.png?branch=master)](https://travis-ci.org/pointhi/OpenSensorSystem)

##Needed-Librarys

* tinyxml2
* lua2.5
* luabind

```sudo apt-get install libtinyxml2-dev libluabind-dev liblua5.2-dev```

##Documentation

I have generate a Doxygen-Documention from the source:
http://doxygen.open-sensor-system.oe5tpo.com/
please note, that this documentation is generated manually, and can be outdated! The easiest is checking the last commit-hash from github and from the documentation.

##Simple Programm

This is a simple Test-File. It load the xml-file(s) and generate a simple tree-structure from it.

```C++
oss::Root SensorSystem; // Generate new OSS-Object

SensorSystem->parseXml("example.xml");   // Loading Data

std::cout << SensorSystem->DrawTree();   // Print Tree-Structure of Data
```

##Example XML-File

Warning: The structure isn't finished design

```XML
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>

<root>
    <i2c name="I2C-0" device="/dev/i2c-0" clock="100kHz" status="disabled">

    </i2c>

    <i2c name="I2C-1" device="/dev/i2c-1" clock="100kHz">
        <i2c-slave name="DIG0_PCF8574A" adress="0x38" maxclock="100kHz" interrupt="yes">
            <lua-script file="lua/i2c/PCF8574.lua">
                <sensor name="BMP_FRONT_LEFT" variable="b0"/>
                <sensor name="BMP_FRONT_MIDDLE" variable="b1"/>
                <sensor name="BMP_FRONT_RIGHT" variable="b2"/>
            </lua-script>
        </i2c-slave>

        <i2c-slave name="DIG1_PCF8574A" adress="0x3A" maxclock="100kHz" interrupt="yes">
            <lua-script file="lua/i2c/PCF8574.lua">
                <sensor name="LINE_LEFT" variable="b0"/>
            </lua-script>
        </i2c-slave>

        <smb-slave name="TMP1_TPA81" adress="0xD0" maxclock="100kHz" interrupt="no">
            <lua-script file="lua/i2c/TPA81.lua">
                <sensor name="ENVIROMENTAL_TEMP" variable="env_temp"/>
                <sensor name="TMP_CAM_0" variable="tmp_cam_0"/>
                <sensor name="TMP_CAM_1" variable="tmp_cam_1"/>
            </lua-script>
        </smb-slave>
    </i2c>
</root>
```
