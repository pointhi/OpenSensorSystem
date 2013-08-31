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

<i2c name="I2C-0" device="/dev/i2c-0" clock="100kHz" status="disabled">

</i2c>

<i2c name="I2C-1" device="/dev/i2c-1" clock="100kHz">
    <i2c-slave name="DIG0_PCF8574A" adress="0x38" maxclock="100kHz" interrupt="yes">

    </i2c-slave>

    <i2c-slave name="DIG1_PCF8574A" adress="0x3A" maxclock="100kHz" interrupt="yes">

    </i2c-slave>

    <smb-slave name="TMP1_SRF80" adress="0xD0" maxclock="100kHz" interrupt="no">

    </smb-slave>
</i2c>
```