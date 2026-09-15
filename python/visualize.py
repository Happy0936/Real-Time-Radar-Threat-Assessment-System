import pandas as pd
import matplotlib.pyplot as plt


# ========================================
# Load Radar Data
# ========================================

data = pd.read_csv("data/radar_log.csv")


# ========================================
# Latest Target Status
# ========================================

latest_data = (
    data.sort_values("cycle")
    .groupby("target_id")
    .tail(1)
)


# ========================================
# Threat Statistics
# ========================================

total_targets = latest_data["target_id"].nunique()

high_threats = (
    latest_data["threat"] == "HIGH"
).sum()

medium_threats = (
    latest_data["threat"] == "MEDIUM"
).sum()

low_threats = (
    latest_data["threat"] == "LOW"
).sum()

processing_cycles = data["cycle"].max()


# ========================================
# Create Dashboard
# ========================================

fig = plt.figure(figsize=(14, 9))

fig.suptitle(
    "REAL-TIME RADAR THREAT ASSESSMENT SYSTEM",
    fontsize=18,
    fontweight="bold"
)


# ========================================
# 1. Radar View
# ========================================

ax1 = fig.add_subplot(2, 2, 1)

ax1.set_title("Radar Target View")

ax1.set_xlim(-1.2, 1.2)
ax1.set_ylim(0, 1.2)

ax1.set_xlabel("Relative Position")
ax1.set_ylabel("Normalized Distance")

ax1.grid(True)

# Radar center
ax1.scatter(0, 0, s=200, marker="o")

# Plot targets
for _, target in latest_data.iterrows():

    distance = target["filtered_distance"]

    normalized_distance = min(
        distance / 3000.0,
        1.0
    )

    x_position = 0.8 * (
        (target["target_id"] % 3) - 1
    )

    ax1.scatter(
        x_position,
        normalized_distance,
        s=120
    )

    ax1.text(
        x_position,
        normalized_distance + 0.04,
        f"ID {int(target['target_id'])}",
        ha="center"
    )


# ========================================
# 2. Target Status
# ========================================

ax2 = fig.add_subplot(2, 2, 2)

ax2.axis("off")

ax2.set_title(
    "Current Target Status",
    fontsize=14
)

status_text = ""

for _, target in latest_data.iterrows():

    status_text += (
        f"Target {int(target['target_id'])}   "
        f"Distance: {target['filtered_distance']:.1f} m   "
        f"Velocity: {target['velocity']:.1f} m/s\n"
        f"Threat: {target['threat']}   "
        f"Decision: {target['decision']}\n\n"
    )

ax2.text(
    0.05,
    0.9,
    status_text,
    verticalalignment="top",
    fontsize=11
)


# ========================================
# 3. System Summary
# ========================================

ax_summary = fig.add_axes(
    [0.68, 0.42, 0.27, 0.20]
)

ax_summary.axis("off")

ax_summary.set_title(
    "System Summary",
    fontsize=14
)

summary_text = (
    f"Total Targets     : {total_targets}\n"
    f"HIGH Threats      : {high_threats}\n"
    f"MEDIUM Threats    : {medium_threats}\n"
    f"LOW Threats       : {low_threats}\n"
    f"Processing Cycles : {processing_cycles}"
)

ax_summary.text(
    0.05,
    0.85,
    summary_text,
    verticalalignment="top",
    fontsize=11
)


# ========================================
# 4. Distance Tracking
# ========================================

ax3 = fig.add_subplot(2, 1, 2)

for target_id in data["target_id"].unique():

    target_data = data[
        data["target_id"] == target_id
    ]

    ax3.plot(
        target_data["cycle"],
        target_data["filtered_distance"],
        marker="o",
        label=f"Target {int(target_id)}"
    )


ax3.set_title("Filtered Target Distance")

ax3.set_xlabel("Radar Cycle")

ax3.set_ylabel("Distance (m)")

ax3.grid(True)

ax3.legend()

plt.tight_layout()

plt.show()