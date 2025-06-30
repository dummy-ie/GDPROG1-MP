# Pokémon Masters EX (Battle Villa) — GDPROG1 Machine Project

This project is a text-based, C-language simulation of the **Battle Villa** mode from *Pokémon Masters EX*. It features a simplified sync pair system, turn-based battles, a 20-floor progressive dungeon, and resource management through an in-game shop.

---

## 💡 Overview

Players must form teams using three types of sync pairs—**STRIKE**, **TECH**, and **SUPPORT**—and battle their way up the **Battle Villa**, a 20-floor tower filled with enemy sync pairs and Elite Four members.

- **STRIKE**: Deals damage (10–20 HP)
- **TECH**: Can flinch opponents (20% chance)
- **SUPPORT**: Heals allies (8–15 HP)

---

## 🧩 Features

### ✅ Sync Pair Management

- Track number of STRIKE, TECH, and SUPPORT sync pairs
- Each type performs unique actions in battle
- Sync pairs begin with 100 HP and can be revived if extras are in reserve

### 🏛️ Battle Villa System

- 20 progressive floors with increasingly difficult battles
- Every 5th floor features a choice between two Elite Four members
- Players can take a **BREAK** between battles to visit the shop
- Losing resets progress to Floor 1

### 🥊 Battle Mechanics

- **3 vs 1** turn-based combat (Player's team vs Enemy sync pair)
- Player selects one sync pair per turn
- Enemies attack based on the player’s last used sync pair
- Flinching disables sync pair action for 2 turns
- Victory grants **gems** and progression
- Loss or forfeit resets to Floor 1

### 🎁 Rewards

- Floor 1–10: 50 gems
- Floor 11–15: 80 gems
- Floor 16–19: 100 gems
- Floor 20: 500 gems
- **Elite Floor Bonus** (every 5th floor):
  - Full Heal
  - 500 Gems
  - Random Gems (100–1000)

### 🛍️ Shop

- Buy STRIKE, TECH, or SUPPORT sync pairs for 200 gems each
- Purchase is restricted based on available gems
- Inventory is updated and displayed accordingly

### 🧭 Navigation & UX

- Intuitive numbered input for navigation
- Full in-game feedback system for actions, events, and errors
- Consistent user prompts to prevent stuck states

---

## 🧠 Technical Highlights

- **Language**: C
- **Interface**: TUI (Terminal User Interface)
- **Core Concepts Used**:
  - Structs for sync pairs and enemy models
  - Randomization for battle outcomes and rewards
  - Conditional logic for flinching, damage, and healing
  - Loops and function-based modularity for game logic

---

## 📦 How to Compile

Use any C compiler (e.g., `gcc`) to compile the program:

```bash
gcc -o pokemon_masters pokemon_masters.c
./pokemon_masters
