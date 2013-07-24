OpenSensorSystem
================

A tree based controll-system to work with sensors, based on xml and lua

**Licence:** GNU GPLv3

**work status:** pre Alpha, still in Developing

##Needed-Librarys

* tinyxml2

##Example XML-File

Warning: at the current state, <?xml... wouldn't work
also, the structure isn't finished design

```XML
<xml version="1.0" encoding="UTF-8" standalone="yes"/>

<i2c name="I2C-0" device="/dev/i2c-0" clock="100kHz" status="disable">

</i2c>

<i2c name="I2C-1" device="/dev/i2c-1" clock="100kHz">
    <i2c-slave>
        <name>DIG0_PCF8574A</name>
        <adress>0x38</adress>
        <generate-interrupt>yes</generate-interrupt>
        <maxclock>100kHz</maxclock>
    </i2c-slave>

    <i2c-slave>
        <name>DIG1_PCF8574A</name>
        <adress>0x3A</adress>
        <generate-interrupt>yes</generate-interrupt>
        <maxclock>100kHz</maxclock>
    </i2c-slave>
</i2c>
```