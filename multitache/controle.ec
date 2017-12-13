const
  threshold_noir : real;
  threshold_blanc : real;
  threshold_distance : real;
  
node controle
  (Collision_n: real;
  Cd_in: real)
returns
  (state_switch_n: bool);

var
  V9_w_001: bool;
  V10_w_002: bool;
  V11_w_003: bool;
  V12_w_004: bool;
  V13_w_005: bool;
  V14_w_006: int;
  V15_w_007: bool;
  V168_w_001: bool;
  V169_w_002: bool;
  V170_w_003: bool;
  V171_w_004: bool;
  V172_w_005: bool;
  V173_w_006: bool;
  V174_w_007: bool;
  V175_w_008: bool;
  V176_w_009: bool;
  V177_w_010: bool;
  V178_w_011: bool;
  V179_w_012: bool;
  V180_w_013: bool;
  V181_w_015: bool;
  V182_w_018: bool;
  V183_w_021: bool;
  V198_w_000: bool;
  V199_w_001: int;
  V200_w_002: bool;
  V201_w_009: bool;
  V202_w_010: bool;
  V203_w_000: bool;
  V204_w_001: bool;
  V205_w_004: bool;
  V206_w_006: bool;
  V207_w_001: bool;
  V208_w_002: bool;
  V209_w_003: bool;
  V210_w_004: bool;
  V211_w_005: bool;
  V212_w_008: bool;

let
  state_switch_n = (V14_w_006 > 1);
  V9_w_001 = (false -> (pre V10_w_002));
  V10_w_002 = (not V12_w_004);
  V11_w_003 = (false -> (pre V13_w_005));
  V12_w_004 = (V14_w_006 = 2);
  V13_w_005 = (V14_w_006 = 3);
  V14_w_006 = (if V200_w_002 then V199_w_001 else 1);
  V15_w_007 = (V171_w_004 and V168_w_001);
  V168_w_001 = (not V9_w_001);
  V169_w_002 = (false -> (pre V15_w_007));
  V170_w_003 = (V176_w_009 and V181_w_015);
  V171_w_004 = (V169_w_002 or V170_w_003);
  V172_w_005 = (not V9_w_001);
  V173_w_006 = (V178_w_011 and V182_w_018);
  V174_w_007 = (V175_w_008 or V173_w_006);
  V175_w_008 = (false -> (pre V176_w_009));
  V176_w_009 = (V174_w_007 and V172_w_005);
  V177_w_010 = (false -> (pre V178_w_011));
  V178_w_011 = (V180_w_013 and V183_w_021);
  V179_w_012 = (Cd_in >= threshold_blanc);
  V180_w_013 = (V177_w_010 or V179_w_012);
  V181_w_015 = (Cd_in >= threshold_blanc);
  V182_w_018 = (Cd_in <= threshold_noir);
  V183_w_021 = (not V9_w_001);
  V198_w_000 = (V204_w_001 and V205_w_004);
  V199_w_001 = (if V198_w_000 then 3 else 2);
  V200_w_002 = (V211_w_005 and V212_w_008);
  V201_w_009 = (V202_w_010 and V15_w_007);
  V202_w_010 = (false -> (pre V200_w_002));
  V203_w_000 = (false -> (pre V198_w_000));
  V204_w_001 = (V203_w_000 or V206_w_006);
  V205_w_004 = (not V11_w_003);
  V206_w_006 = (V201_w_009 >= true);
  V207_w_001 = (0.000000 <= Collision_n);
  V208_w_002 = (V207_w_001 and V209_w_003);
  V209_w_003 = (Collision_n <= threshold_distance);
  V210_w_004 = (false -> (pre V200_w_002));
  V211_w_005 = (V210_w_004 or V208_w_002);
  V212_w_008 = (not V11_w_003);
tel

