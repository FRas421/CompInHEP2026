import re
import sys
from pathlib import Path


def main():
    log_path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("brilcalc.log")
    if not log_path.exists():
        raise SystemExit(f"ERROR: file not found: {log_path}")

    text = log_path.read_text(encoding="utf-8", errors="replace")

    m = re.search(
        r"\|\s*nfill\s*\|\s*nrun\s*\|\s*nls\s*\|\s*ncms\s*\|\s*totdelivered\(/pb\)\s*\|\s*totrecorded\(/pb\)\s*\|"
        r".*?\n"
        r"\+[-+]+\+\n"
        r"\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*([0-9.]+)\s*\|\s*([0-9.]+)\s*\|",
        text,
        flags=re.IGNORECASE | re.DOTALL,
    )

    if not m:
        raise SystemExit("ERROR: Could not find the summary 'totrecorded(/pb)' row in the log.")

    tot_recorded_pb = float(m.group(2))
    tot_recorded_fb = tot_recorded_pb / 1000.0
    print(f"{tot_recorded_fb:.1f} fb^-1")

if __name__ == "__main__":
    main()
