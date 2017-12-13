const
  kp_teta : real;
  ki_teta : real;
  T : real;
  pi : real;
  
node decision
  (Cg: real;
  Cd: real;
  state_bool_n: real)
returns
  (v_d: real;
  v_g: real;
  Cd_out: real);

var
  V14_w_002: real;
  V16_w_004: real;
  V19_w_007: real;
  V20_w_008: real;
  V106_w_000: real;
  V107_w_001: real;
  V108_w_002: real;
  V109_w_003: real;
  V110_w_004: real;
  V111_w_005: real;
  V112_w_009: real;
  V113_w_010: real;
  V114_w_011: real;
  V115_w_012: real;
  V116_w_014: real;
  V117_w_015: real;
  V118_w_016: real;
  V119_w_017: real;
  V120_w_018: real;
  V121_w_019: real;
  V138_w_004: real;

let
  v_d = (if (state_bool_n <> 0.000000) then -0.500000 else V19_w_007);
  v_g = (if (state_bool_n <> 0.000000) then 0.500000 else V20_w_008);
  Cd_out = Cd;
  V14_w_002 = (Cd_out + Cg);
  V16_w_004 = ((pi / 200.000000) * V138_w_004);
  V19_w_007 = (0.500000 * V119_w_017);
  V20_w_008 = (0.500000 * V118_w_016);
  V106_w_000 = (0.000000 -> (pre V111_w_005));
  V107_w_001 = (V108_w_002 * V109_w_003);
  V108_w_002 = (0.500000 * T);
  V109_w_003 = (V110_w_004 + V16_w_004);
  V110_w_004 = (0.000000 -> (pre V16_w_004));
  V111_w_005 = (V107_w_001 + V106_w_000);
  V112_w_009 = (V121_w_019 + V120_w_018);
  V113_w_010 = ((-V115_w_012) + V116_w_014);
  V114_w_011 = (2.000000 * V113_w_010);
  V115_w_012 = (if (V117_w_015 < 0.000000) then (-V117_w_015) else V117_w_015);
  V116_w_014 = (0.005000 * V14_w_002);
  V117_w_015 = (2.000000 * V112_w_009);
  V118_w_016 = ((-V112_w_009) + V114_w_011);
  V119_w_017 = (V112_w_009 + V114_w_011);
  V120_w_018 = (kp_teta * V16_w_004);
  V121_w_019 = (ki_teta * V111_w_005);
  V138_w_004 = (Cd_out - Cg);
tel

