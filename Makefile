# ------------------------------- lily58 druotoni

lily_druotoni_keymap_path := ./keyboards/lily58/keymaps/druotoni

.PHONY: lily_json2c
lily_json2c:
	qmk json2c $(lily_druotoni_keymap_path)/lily58_rev1.json > $(lily_druotoni_keymap_path)/keymap.c

.PHONY: lily_build_left
lily_build_left:
	sed -i -e 's/IS_RIGHT/IS_LEFT/g' $(lily_druotoni_keymap_path)/config.h
	qmk compile -kb lily58 -km druotoni

.PHONY: lily_build_right
lily_build_right:
	sed -i -e 's/IS_LEFT/IS_RIGHT/g' $(lily_druotoni_keymap_path)/config.h
	qmk compile -kb lily58 -km druotoni

.PHONY: lily_flash_left
lily_flash_left: lily_json2c lily_build_left
	echo 'Присоединить ЛЕВУЮ половинку и нажать RESET'
	qmk flash -kb lily58 -km druotoni

.PHONY: lily_flash_right
lily_flash_right: lily_json2c lily_build_right
	echo 'Присоединить ПРАВУЮ половинку и нажать RESET'
	qmk flash -kb lily58 -km druotoni

.PHONY:
lily_flash_both: lily_flash_right lily_flash_left


# ------------------------------- sofle

sofle_druotoni_keymap_path := ./keyboards/sofle/keymaps/druotoni/

.PHONY: sofle_json2c
sofle_json2c:
	qmk json2c $(sofle_druotoni_keymap_path)/sofle_rev1_layout.json > $(sofle_druotoni_keymap_path)/keymap.c

.PHONY: sofle_build_left
sofle_build_left:
	sed -i -e 's/IS_RIGHT/IS_LEFT/g' $(sofle_druotoni_keymap_path)/config.h
	qmk compile -kb sofle -km druotoni

.PHONY: sofle_build_right
sofle_build_right:
	sed -i -e 's/IS_LEFT/IS_RIGHT/g' $(sofle_druotoni_keymap_path)/config.h
	qmk compile -kb sofle -km druotoni

.PHONY: sofle_flash_left
sofle_flash_left: sofle_json2c sofle_build_left
	echo 'Присоединить ЛЕВУЮ половинку и нажать RESET'
	qmk flash -kb sofle -km druotoni

.PHONY: sofle_flash_right
sofle_flash_right: sofle_json2c sofle_build_right
	echo 'Присоединить ПРАВУЮ половинку и нажать RESET'
	qmk flash -kb sofle -km druotoni

.PHONY:
sofle_flash_both: sofle_flash_right sofle_flash_left

