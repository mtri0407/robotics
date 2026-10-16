# VEX V5 Robot Arm

Control code for the two-joint (2-DOF) robot arm of my VEX Robotics Competition team, written in C++ with VEXcode V5. I was the team's control systems developer from April to August 2026.

[English](#english) · [Tiếng Việt](#tieng-viet)

<a id="english"></a>

## English

### What it does

- **Shoulder** joint on port 1, **elbow** joint on port 2 (V5 Smart Motors, 18:1 gear cartridge).
- Driver control from the V5 controller: shoulder on **L1 / L2**, elbow on **R1 / R2**.
- When a button is released, each joint stops in `hold` mode, so the arm keeps its position against gravity instead of dropping (`coast`) or snapping (`brake`).
- The control loop runs every 20 ms, which keeps the arm responsive without overloading the V5 Brain.

### Working with the hardware team

I worked with the hardware engineers to calibrate motor outputs, sensor feedback and trajectory accuracy.

### Files

| File | Purpose |
|---|---|
| [`vex-v5-robot-arm/RobotArm.v5cpp`](vex-v5-robot-arm/RobotArm.v5cpp) | Original VEXcode V5 project, open it in VEXcode to download to the robot |
| [`vex-v5-robot-arm/main.cpp`](vex-v5-robot-arm/main.cpp) | The same code extracted so it can be read on GitHub |

<a id="tieng-viet"></a>

## Tiếng Việt

Mã điều khiển cánh tay robot hai khớp (vai, khuỷu) của đội thi VEX Robotics Competition, viết bằng C++ trên VEXcode V5. Mình phụ trách lập trình điều khiển của đội từ tháng 4 đến tháng 8/2026.

- Vai điều khiển bằng nút L1/L2, khuỷu bằng R1/R2.
- Buông nút thì khớp dừng ở chế độ `hold`, giữ nguyên vị trí chứ không rơi xuống theo trọng lực.
- Phối hợp với nhóm phần cứng cân chỉnh động cơ, cảm biến và độ chính xác quỹ đạo.

---

**Phạm Nguyễn Minh Trí** · [GitHub @mtri0407](https://github.com/mtri0407)
