
# Enhanced MV and CP (`smartmv` and `smartcp`)

**Enhanced MV and CP** is a C-based utility that extends the functionality of the traditional `mv` and `cp` commands. It introduces the `-e` flag, which allows intelligent root path handling, simplifying file and directory operations.

---

## Features

- **Root Path Handling (`-e`):** Automatically reuses the root path of the source for destination operations.
- **Recursive Operations (`-r`):** Fully supports standard options like `-r` for recursive operations.
- **Flexible Command Usage:** Works seamlessly for both `mv` and `cp`, based on the executable name.

---

## Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:erwanclx/smarter-file-tools.git
   cd smarter-file-tools
   ```

2. Compile the source code using the Makefile:
   ```bash
   make
   ```

3. This will create two executables: `smartmv` and `smartcp`.

4. (Optional) Add them to your executable path for easier access:
   ```bash
   sudo mv smartmv /usr/local/bin/
   sudo mv smartcp /usr/local/bin/

# Enhanced MV and CP (`smartmv` and `smartcp`)

**Enhanced MV and CP** is a C-based utility that extends the functionality of the traditional `mv` and `cp` commands. It introduces the `-e` flag, which allows intelligent root path handling, simplifying file and directory operations.

---

## Features

- **Root Path Handling (`-e`):** Automatically reuses the root path of the source for destination operations.
- **Original flags of `cp` and `mv` tools
- **Flexible Command Usage:** Works seamlessly for both `mv` and `cp`, based on the executable name.

---

## Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:erwanclx/smarter-file-tools.git
   cd smarter-file-tools
   ```

2. Compile the source code using the Makefile:
   ```bash
   make
   ```

3. This will create two executables: `smartmv` and `smartcp`.

4. (Optional) Add them to your executable path for easier access:
   ```bash
   sudo mv smartmv /usr/local/bin/
   sudo mv smartcp /usr/local/bin/

---

## Usage

### smartmv

Move files or directories with intelligent root path handling.

**Syntax:**
*All the original cp and mv flag works, so you can be recursive with -r, verbose with -v, etc*

```bash
smartmv [OPTIONS] SOURCE DEST
```

- `-e` (Optional): Automatically reuses the root path of the source for the destination.

**Example:**
```bash
smartmv -e /home/user/docs backup
```

### smartcp

Copy files or directories with intelligent root path handling.

**Syntax:**
*All the original cp and mv flag works, so you can be recursive with -r, verbose with -v, etc*

```bash
smartcp [OPTIONS] SOURCE DEST
```

- `-e` (Optional): Automatically reuses the root path of the source for the destination.

**Example:**
```bash
smartcp -e /home/user/docs /backup
```

---

## Contribution

Feel free to open issues or submit pull requests to improve the functionality or address bugs. Contributions are always welcome!
