# Описание

Раскладка druotoni для lily58

## Подготовка

```bash
git clone https://github.com/Feelinglight/qmk_firmware.git
cd qmk_firmware
git submodule update -j 8 --init --recursive
uv venv
uv pip install qmk
```

## Прошивка

- Левая половинка:

  - Подключить type-c к левой половинке
  - Выполнить

    ```bash
    uv run make sofle_flash_left
    # uv run make lily_flash_left
    ```

  - Нажать RESET

- Правая половинка:

  - Подключить type-c к правой половинке
  - Выполнить

    ```bash
    uv run make sofle_flash_right
    # uv run make lily_flash_right
    ```

  - Нажать RESET

## Изменение раскладки

Раскладка меняется через [Web UI](https://config.qmk.fm/#/lily58/rev1/LAYOUT)

В конфигуратор загружается файл **./keyboards/lily58/keymaps/druotoni/**, меняется раскладка и
загружается измененная json-конфигурация.

Для генерации c-файла выполнить ``make json2c``

## Слои sofle

![](keyboards/sofle/keymaps/druotoni/images/0.png)

![](keyboards/sofle/keymaps/druotoni/images/1.png)

![](keyboards/sofle/keymaps/druotoni/images/2.png)

![](keyboards/sofle/keymaps/druotoni/images/3.png)

![](keyboards/sofle/keymaps/druotoni/images/4.png)

![](keyboards/sofle/keymaps/druotoni/images/5.png)


## Слои lily58

![](keyboards/lily58/keymaps/druotoni/images/0.png)

![](keyboards/lily58/keymaps/druotoni/images/1.png)

![](keyboards/lily58/keymaps/druotoni/images/2.png)

![](keyboards/lily58/keymaps/druotoni/images/3.png)

![](keyboards/lily58/keymaps/druotoni/images/4.png)

![](keyboards/lily58/keymaps/druotoni/images/5.png)

