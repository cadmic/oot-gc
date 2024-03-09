#!/bin/bash

set -euo pipefail

# Injects a custom .dol and ROMs into the MQ ISO. Requires gcmdump and gcmasm to be on the PATH.
# Usage:
#   tools/gc_inject.sh ORIGINAL_ISO -o OUTPUT_ISO [--dol DOL] [--rom ROM] [--mq-rom MQ_ROM]

GAME_ID="DGZJ01"
GAME_NAME="GZ GC-J & MQ-J"
OUTPUT_ISO=""
DOL=""
ROM=""
MQ_ROM=""
ORIGINAL_ISO=""

# Parse arguments
while [[ $# -gt 0 ]]; do
  key="$1"
  case $key in
    -o|--output)
      OUTPUT_ISO="$2"
      shift
      shift
      ;;
    --dol)
      DOL=$(realpath "$2")
      shift
      shift
      ;;
    --rom)
      ROM=$(realpath "$2")
      shift
      shift
      ;;
    --mq-rom)
      MQ_ROM=$(realpath "$2")
      shift
      shift
      ;;
    *)
      ORIGINAL_ISO=$(realpath "$1")
      shift
      ;;
  esac
done

# Check if required arguments are set
if [ -z "$ORIGINAL_ISO" ] || [ -z "$OUTPUT_ISO" ]; then
  echo "Usage: $0 ORIGINAL_ISO -o OUTPUT_ISO [--dol DOL] [--rom ROM] [--mq-rom MQ_ROM]"
  exit 1
fi

ISO_DIR="/tmp/oot_iso"
TGC_DIR="/tmp/oot_tgc"

# Create temporary directories
mkdir -p $ISO_DIR
trap "rm -rf $ISO_DIR" EXIT

mkdir -p $TGC_DIR
trap "rm -rf $TGC_DIR" EXIT

# Extract files
(cd $ISO_DIR && gcmdump "$ORIGINAL_ISO")
(cd $TGC_DIR && gcmdump --tgc "$ISO_DIR/zlj_f.tgc")

# Delete unnecessary files
ls $ISO_DIR/*.tgc | grep -v zlj_f.tgc | xargs rm
rm $TGC_DIR/final_zelda_credits_sound.thp

# Inject custom files
if [ -n "$DOL" ]; then
  cp "$DOL" "$TGC_DIR/default.dol"
fi

if [ -n "$ROM" ]; then
  cp "$ROM" "$TGC_DIR/zlj_f.n64"
fi

if [ -n "$MQ_ROM" ]; then
  cp "$MQ_ROM" "$TGC_DIR/urazlj_f.n64"
fi

# Rebuild ISO
gcmasm --tgc --game-id="$GAME_ID" --name="$GAME_NAME" "$TGC_DIR" "$ISO_DIR/zlj_f.tgc"
gcmasm --game-id="$GAME_ID" --name="$GAME_NAME" "$ISO_DIR" "$OUTPUT_ISO"
