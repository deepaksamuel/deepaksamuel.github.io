EIC-DRICH parameters (for pedagogical purposes only)
---

### DRICH Detector Parameters

| **Parameter**                     | **Value**                                                                 |
|-----------------------------------|---------------------------------------------------------------------------|
| **Detector Name**                 | DRICH                                                                     |
| **Detector ID**                   | `ForwardRICH_ID` (ID: 120)                                                |
| **Geometry**                      |                                                                           |
| - ForwardRICHRegion_length        | `PIDRegion_length-TOF_length`  = 135 cm - 15 cm  = 120 cm                 |
| - ForwardRICHRegion_zmin          | `Centraltracing_zmax-TOF_length`  = 1800 mm -15 cm  = 165 cm              |
| - Vessel Length                   | `DRICH_length = ForwardRICHRegion_length` = 120 cm                        |
| - Vessel Z-min                    | `DRICH_zmin = ForwardRICHRegion_zmin + 3.0*cm`  =195 cm                   |
| - Vessel Z-max                    | `DRICH_zmax = DRICH_zmin + DRICH_length` = 195 cm + 120 cm = 315 cm       |
| - Bore Radius (Front)             | `DRICH_rmin0 = DRICH_zmin * ForwardRICHRegion_tan1`                       |
| - Bore Radius (Back)              | `DRICH_rmin1 = DRICH_zmax * ForwardRICHRegion_tan2`                       |
| - Wall Thickness                  | `DRICH_wall_thickness = 1.0*cm`                                           |
| - Window Thickness                | `DRICH_window_thickness = 0.3*cm`                                         |
| - Number of Sectors               | `DRICH_num_sectors = 6`                                                   |
| **Snout Geometry**                |                                                                           |
| - Snout Length                    | `DRICH_snout_length = 20.0*cm`                                            |
| - Snout Radius (Front)            | `DRICH_rmax0 = 90.0*cm`                                                   |
| - Snout Radius (Back)             | `DRICH_rmax1 = DRICH_rmax0 + DRICH_snout_length * tan(0.200 + atan(DRICH_rmax0/DRICH_zmin)` |
| **Tank Geometry**                 |                                                                           |
| - Tank Radius                     | `DRICH_rmax2 = ForwardPIDRegion_rmax` = 180 cm                            |
| **Sensor Boxes**                  |                                                                           |
| - Sensor Box Length               | `DRICH_sensorbox_length = 50.0*cm`                                        |
| - Sensor Box R-min                | `DRICH_sensorbox_rmin = 108*cm`                                           |
| - Sensor Box R-max                | `DRICH_sensorbox_rmax = DRICH_rmax2 + 5*cm`                               |
| - Sensor Box Azimuthal Width      | `DRICH_sensorbox_dphi = 42*degree`                                        |
| **Radiator**                      |                                                                           |
| - Aerogel Thickness               | `DRICH_aerogel_thickness = 4.0*cm`                                        |
| - Air Gap Thickness               | `DRICH_airgap_thickness = 0.01*mm`                                        |
| - Filter Thickness                | `DRICH_filter_thickness = 3.0*mm`                                         |
| **Sensors**                       |                                                                           |
| - Pixel Gap                       | `DRICH_pixel_gap = 0.2*mm`                                                |
| - Sensor Resin Size               | `DRICH_sensor_resin_size = 25.8*mm`                                       |
| - Sensor Size                     | `DRICH_sensor_size = DRICH_sensor_resin_size - DRICH_pixel_gap`           |
| - Sensor Thickness                | `DRICH_sensor_thickness = 0.1*mm`                                         |
| - Sensor Resin Thickness          | `DRICH_sensor_resin_thickness = 1.35*mm`                                  |
| - Number of Pixels                | `DRICH_num_px = 8`                                                        |
| - Pixel Size                      | `DRICH_pixel_size = 3.0*mm`                                               |
| - Pixel Pitch                     | `DRICH_pixel_pitch = DRICH_pixel_size + DRICH_pixel_gap`                  |
| **Photodetector Unit (PDU)**      |                                                                           |
| - PDU Number of Sensors           | `DRICH_pdu_num_sensors = 2`                                               |
| - PDU Sensor Gap                  | `DRICH_pdu_sensor_gap = 0.2*mm`                                           |
| - PDU Gap                         | `DRICH_pdu_gap = 3.0*mm`                                                  |
| **Materials**                     |                                                                           |
| - Vessel Material                 | `Aluminum`                                                                |
| - Radiator Aerogel Material       | `Aerogel_DRICH`                                                           |
| - Radiator Filter Material        | `Acrylic_DRICH`                                                           |
| - Gas Material                    | `C2F6_DRICH`                                                              |
| - Mirror Material                 | `Acrylic_DRICH`                                                           |
| **Optical Properties**            |                                                                           |
| - Mirror Reflectivity             | `REFLECTIVITY_mirror` (90% reflectivity)                                  |
| - Sensor Efficiency               | `SensorSurface_DRICH` (100% efficiency)                                   |
| **Readout**                       |                                                                           |
| - Readout Name                    | `DRICHHits`                                                               |
| - Segmentation Type               | `CartesianGridXY`                                                         |
| - Grid Size                       | `DRICH_pixel_pitch` (3.2 mm)                                              |
| - Offset                          | `-0.5*(DRICH_num_px-1)*DRICH_pixel_pitch`                                 |

---

### Notes:
1. **Vessel Geometry**: The DRICH vessel consists of a **snout** (conical front) and a **tank** (cylindrical main volume). The snout houses the aerogel radiator, while the tank contains the majority of the detector components. The gas volume fills this vessel and all the other volumes are childrens.
2. **Radiator**: There are two radiators. The first radiator is composed of **aerogel** and a **filter**, separated by a small air gap. The aerogel thickness is 4.0 cm, and the filter thickness is 3.0 mm. The second radiator is a gas.
3. **Sensors**: The sensors are arranged in **Photodetector Units (PDUs)**, each containing a 2x2 matrix of sensors. The sensors have a pixel size of 3.0 mm and a pitch of 3.2 mm.
4. **Optical Properties**: The mirror has a reflectivity of 90%, and the sensors have 100% efficiency for detecting photons.
5. **Materials**: The vessel is made of **aluminum**, the radiator uses **aerogel** and **acrylic**, and the gas inside the detector is **C₂F₆**.

---

