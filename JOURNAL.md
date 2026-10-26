---
title: "splittie"
github: "https://github.com/Bananaking23/splittie"
description: "I am going to design a board about 18.5x18.5mm in size, it will include leds, kailh switches and diodes, and i am going to create a split keyboard with it."
created_at: "2026-10-22"
total_time: "19h 6m"
---

# October 22, 2026: started schematic
<!-- fabricate:entry 1034 -->

![](https://fabricate.hackclub-assets.com/446375e94cffccfc2158f506713c2cbc35e20a8f3376536ed8e36ab30c4234ee/image-png/image.png)
I have added my microcontroller, it is a rp2040 pro micro due to its many available gpio pins, i have also created a sheet for my switch cell, and duplicated it 20 times for 20 switches per board, and since jlc pcb gives 5 boards, it will have 100 switches which i can use to create a keyboard, in any layout i want.

![](https://fabricate.hackclub-assets.com/05832df918aa654052c9ab0f1a833561b46c045f96761de3f44e9c0ff7292005/image-png/image.png)

I am going to add the rotary encoder next and create the pcb

**Total time spent: 1h**

# October 24, 2026: routed pcb
<!-- fabricate:entry 1170 -->

![](https://fabricate.hackclub-assets.com/3904b2df3c2a8ebd313a9c591154560dee27709466b95af6329220cf7be20c97/image-png/image.png)
i have finished placing everything and routing my pcb, it has 1mm space inbetween all cells, so i can use vcuts,
![](https://fabricate.hackclub-assets.com/447316d25894c77b65206eb5da421b7b2fda49b5f53ea524bab721817f2ae308/image-png/image.png)
i am not great at routing, so this took me a while. i am going to create a case next

**Total time spent: 5h**

# October 24, 2026 (entry 2): panelization
<!-- fabricate:entry 1220 -->

I have decided that mousebites are probably a better way to go, because you cant have vcuts halfway across a panel with jlcpcb, I have added mousebites to both sides, and now only need to them inbetween the microcontroller and switches

![](https://fabricate.hackclub-assets.com/8b774206e23dea9fab9cf7b4c825c6291c54ec069cd9ce9fd3509bcdbb09df69/image-png/image.png)
![](https://fabricate.hackclub-assets.com/4d12e95ddd0841cd5c549e52738e6d8cbbf05800b7dac80e4b5be9b5597e7955/image-png/image.png)

it took me a while to get it working, as they are stupidly difficult for me.

**Total time spent: 5h 6m**

# October 24, 2026 (entry 3): finished pcb
<!-- fabricate:entry 1225 -->

![](https://fabricate.hackclub-assets.com/8c07c3ef10a23a18f4b940b21832022d15ee40c5cf91b69326313de44bc77d68/image-png/image.png)
connected them together, i am going to do the case next hopefully, which may be a pain. i moved it to the right side because it was much easier to do on that side.

**Total time spent: 30m**

# October 25, 2026: case
<!-- fabricate:entry 1257 -->

I have decided i am going to use a layout like the sofle, i copied a layout.dxf from ergo gen and added some mounting holes, i also added my own measurements for the microcontroller and oled then extruded it 

![](https://fabricate.hackclub-assets.com/d2dfef3e8d238c7ca321dddfd0917c19178717e6d69556f7ac6238a5cd3ae0ce/image-png/image.png)

i also copied it and flipped it for the other side.
![](https://fabricate.hackclub-assets.com/aaa379a561822d402dfd9f086ddd675ba28bbac3377b7b5ec963a310ff539354/image-png/image.png)
I made sure it can be printed on my a1mini because it is relatively small.
I have also created a casing and mirrored it, i think it came out great, hopefully it actually works when I print it as i am not great at cad
![](https://fabricate.hackclub-assets.com/940ae61679fe8b410d7363cb4243f84d2fb1cd23bec21c76296c75ac9ca69b4e/image-png/image.png)

**Total time spent: 6h**

# October 26, 2026: created software
<!-- fabricate:entry 1285 -->

![](https://fabricate.hackclub-assets.com/3043717dab1d4d67cfc84df405b422e19c5bd0bb4187c5896c544f8c5e00158e/image-png/image.png)
I have created the software using qmk and via, I hope it works because i am not great at using qmk or coding. i am going to create the github  next, which will be much easier then the rest of the project

**Total time spent: 1h 30m**
