# Porting the EEPROM Contract

Hardware Definitions can describe physical capacity and programming geometry. An Adapter can expose a smaller mapped region and must report that effective size. Targets vary in page boundaries, endurance, write latency and power-loss behavior. A nonvolatile implementation can use this contract when it supports the documented byte semantics and can confirm completion within its timeout rules.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
