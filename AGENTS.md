# Repository Guidelines

## Project Structure & Module Organization
- Core notes: `outline.md` (syllabus/outline), running examples in `sim_examples.md`.
- Keep lecture materials as Markdown first. If structure grows:
  - `notes/` weekly/topic notes (e.g., `notes/week-03-axi.md`).
  - `slides/` Marp slide sources (`*.md`) and exported `*.pdf`.
  - `assets/` figures and diagrams referenced by notes/slides.
- Code is optional and minimal. Prefer inline fenced snippets inside notes.

## Build, Test, and Development Commands
- Preview Markdown: use your editor’s Markdown preview.
- Slide export (Marp): `marp slides/week-01.md --pdf -o slides/week-01.pdf`.
- Markdown lint (optional): `markdownlint **/*.md` or `npx markdownlint-cli .`.
- Link check (optional): `lychee **/*.md` or any equivalent link checker.

## Coding Style & Naming Conventions
- Markdown: one `#` H1 per file; use meaningful headings; prefer bullets over long paragraphs.
- File names: `week-02-dsp-accelerator.md`, `topic-axi-basics.md` (lowercase, hyphenated).
- Snippets: short, didactic examples with language tags (e.g., ```verilog, ```c, ```python) and a one‑line purpose comment.
- Figures: store under `assets/`, reference with relative paths, include alt text.
- Prefer Figures and Code snippets where possible instead of plain text or bullet points

## Testing Guidelines
- Validate clarity: each section should state objectives, prerequisites, and outcomes.
- For code snippets: keep runnable size small; include expected output or brief explanation; pseudocode is fine if full code distracts from learning goals.
- For links/images: run a link checker periodically; verify images render in both notes and slides.

## Commit & Pull Request Guidelines
- Commits: concise, present tense. Example: `docs(week-03): add AXI handshake notes`.
- Be sure to commit after every non-trivial change.
- PRs: include summary, scope (weeks/topics affected), screenshots of slide diffs when relevant, and any link-check output.
- Keep diffs focused on pedagogy; avoid introducing large code artifacts unless explicitly requested.

## Security & Configuration Tips
- Do not commit large binaries, bitstreams, or secrets; link externally when needed.
- Prefer small, source-controlled assets (SVG/PNG). Generate PDFs from slides on demand.
