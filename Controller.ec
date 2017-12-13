const
  kp_teta : real;
  ki_teta : real;
  T : real;
  threshold_noir : real;
  threshold_blanc : real;
  threshold_distance : real;
  pi : real;
  
node Controller
  (Cg: real;
  Cd: real;
  Collision_n: real)
returns
  (v_d: real;
  v_g: real);

var
  V15_w_001: bool;
  V16_w_002: bool;
  V17_w_003: bool;
  V19_w_005: bool;
  V20_w_006: bool;
  V22_w_008: real;
  V24_w_010: real;
  V25_w_011: int;
  V26_w_012: bool;
  V30_w_016: real;
  V31_w_017: real;
  V246_w_000: real;
  V247_w_001: real;
  V248_w_002: real;
  V249_w_003: real;
  V250_w_004: real;
  V251_w_005: real;
  V252_w_009: real;
  V253_w_010: real;
  V254_w_011: real;
  V255_w_012: real;
  V256_w_014: real;
  V257_w_015: real;
  V258_w_016: real;
  V259_w_017: real;
  V260_w_018: real;
  V261_w_019: real;
  V278_w_001: bool;
  V279_w_002: bool;
  V280_w_003: bool;
  V281_w_004: bool;
  V282_w_005: bool;
  V283_w_006: bool;
  V284_w_007: bool;
  V285_w_008: bool;
  V286_w_009: bool;
  V287_w_010: bool;
  V288_w_011: bool;
  V289_w_012: bool;
  V290_w_013: bool;
  V291_w_015: bool;
  V292_w_018: bool;
  V293_w_021: bool;
  V310_w_000: bool;
  V311_w_001: int;
  V312_w_002: bool;
  V313_w_009: bool;
  V314_w_010: bool;
  V315_w_000: bool;
  V316_w_001: bool;
  V317_w_004: bool;
  V318_w_006: bool;
  V319_w_001: bool;
  V320_w_002: bool;
  V321_w_003: bool;
  V322_w_004: bool;
  V323_w_005: bool;
  V324_w_008: bool;
  V338_w_004: real;

let
  v_d = (if (V25_w_011 > 1) then -0.500000 else V30_w_016);
  v_g = (if (V25_w_011 > 1) then 0.500000 else V31_w_017);
  V15_w_001 = (false -> (pre V16_w_002));
  V16_w_002 = (not V19_w_005);
  V17_w_003 = (false -> (pre V20_w_006));
  V19_w_005 = (V25_w_011 = 2);
  V20_w_006 = (V25_w_011 = 3);
  V22_w_008 = (Cd + Cg);
  V24_w_010 = ((pi / 200.000000) * V338_w_004);
  V25_w_011 = (if V312_w_002 then V311_w_001 else 1);
  V26_w_012 = (V281_w_004 and V278_w_001);
  V30_w_016 = (0.500000 * V259_w_017);
  V31_w_017 = (0.500000 * V258_w_016);
  V246_w_000 = (0.000000 -> (pre V251_w_005));
  V247_w_001 = (V248_w_002 * V249_w_003);
  V248_w_002 = (0.500000 * T);
  V249_w_003 = (V250_w_004 + V24_w_010);
  V250_w_004 = (0.000000 -> (pre V24_w_010));
  V251_w_005 = (V247_w_001 + V246_w_000);
  V252_w_009 = (V261_w_019 + V260_w_018);
  V253_w_010 = ((-V255_w_012) + V256_w_014);
  V254_w_011 = (2.000000 * V253_w_010);
  V255_w_012 = (if (V257_w_015 < 0.000000) then (-V257_w_015) else V257_w_015);
  V256_w_014 = (0.005000 * V22_w_008);
  V257_w_015 = (2.000000 * V252_w_009);
  V258_w_016 = ((-V252_w_009) + V254_w_011);
  V259_w_017 = (V252_w_009 + V254_w_011);
  V260_w_018 = (kp_teta * V24_w_010);
  V261_w_019 = (ki_teta * V251_w_005);
  V278_w_001 = (not V15_w_001);
  V279_w_002 = (false -> (pre V26_w_012));
  V280_w_003 = (V286_w_009 and V291_w_015);
  V281_w_004 = (V279_w_002 or V280_w_003);
  V282_w_005 = (not V15_w_001);
  V283_w_006 = (V288_w_011 and V292_w_018);
  V284_w_007 = (V285_w_008 or V283_w_006);
  V285_w_008 = (false -> (pre V286_w_009));
  V286_w_009 = (V284_w_007 and V282_w_005);
  V287_w_010 = (false -> (pre V288_w_011));
  V288_w_011 = (V290_w_013 and V293_w_021);
  V289_w_012 = (Cd >= threshold_blanc);
  V290_w_013 = (V287_w_010 or V289_w_012);
  V291_w_015 = (Cd >= threshold_blanc);
  V292_w_018 = (Cd <= threshold_noir);
  V293_w_021 = (not V15_w_001);
  V310_w_000 = (V316_w_001 and V317_w_004);
  V311_w_001 = (if V310_w_000 then 3 else 2);
  V312_w_002 = (V323_w_005 and V324_w_008);
  V313_w_009 = (V314_w_010 and V26_w_012);
  V314_w_010 = (false -> (pre V312_w_002));
  V315_w_000 = (false -> (pre V310_w_000));
  V316_w_001 = (V315_w_000 or V318_w_006);
  V317_w_004 = (not V17_w_003);
  V318_w_006 = (V313_w_009 >= true);
  V319_w_001 = (0.000000 <= Collision_n);
  V320_w_002 = (V319_w_001 and V321_w_003);
  V321_w_003 = (Collision_n <= threshold_distance);
  V322_w_004 = (false -> (pre V312_w_002));
  V323_w_005 = (V322_w_004 or V320_w_002);
  V324_w_008 = (not V17_w_003);
  V338_w_004 = (Cd - Cg);
tel

