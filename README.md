# SumoBot v2
A significantly improved version of [SumoBot v1](https://github.com/choicebuilds/SumoBot-v1)!  Concise documentation intended as a project showcase for my portfolio/resume.
<img src="https://github.com/choicebuilds/SumoBot-v2/blob/main/pictures/final_bot.jpg" alt="SumoBot" width="1000"/>  
Notable Improvements:
- 4-layer PCB with dedicated 9V/5V planes and a solid ground plane to improve return current paths and help reduce EMI
- Decoupling & bulk capacitors placed throughout the board for improved power integrity
- STM32 MCU + STM32CubeMX + C/Cmake Firmware
- Various quality of life additions (e.g. strategy switch, remote start, on/off switch, etc.)
- Compact layout featuring 0402 surface-mount components (ft. dog-bone fanout for motor drivers for space and cost)
 
## Hardware Showcase
<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Schematic.png" alt="Schematic" width="800"/>

<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Layout.png" alt="Layout" width="800"/>

<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Top.png" alt="Top" width="400"/> <img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Bottom.png" alt="Bottom" width="400"/>

<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Power-Planes.png" alt="Power-Planes" width="400"/> <img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/Kamikazii-Solid-GND-Plane.png" alt="Solid-GND-Plane" width="400"/>

<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/pcb_front.png" alt="Top" width="400"/> <img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/pcb_back.png" alt="Bottom" width="400"/>

## Soldering Showcase
With the JLCPCB Stencil: $14.16 (PCB) + $21.69 (Shipping) - $5 (Coupon) = $30.85 + Tax  
Without the JLCPCB Stencil: $7 (PCB) + $3.12 (Shipping) - $5 (Coupon) = $5.12 + Tax  
I went with the second option and generated a stencil using the LPKF Protolaser.  
<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/stencil_front.png" alt="Front of Stencil" width="400"/> <img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/stencil_back.png" alt="Back of Stencil" width="400"/>  
I would not recommend, especially for a small PCB, because the stencil did not sit flat. Required a few manual adjustments.  
<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/stencil_solder.png" alt="Solder Applied" width="800"/>  
Then, a reflow oven was used for SMD components:  
<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/protoflow.png" alt="LPKF Protoflow" width="400"/> <img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/protoflow_2.png" alt="SMD Complete" width="400"/>  
And the remaining components were through-hole soldered.

## WARNING
I flipped the polarity of the XT-30 connector on the silkscreen without reverse-polarity protection:  
<img src="https://github.com/choicebuilds/Kamii/blob/main/pictures/blown_capacitor.jpg" alt="Blown Up Capacitor" width="1000"/>  
It made a very loud sound when the bulk capacitor blew up. Lesson learned to always double check.

## Demo Video
[<img src="https://img.youtube.com/vi/7yXx8vgZZFc/hqdefault.jpg" width="1600" height="900"/>](https://www.youtube.com/watch?v=7yXx8vgZZFc)  
